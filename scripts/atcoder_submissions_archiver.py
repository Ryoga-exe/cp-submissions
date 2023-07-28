import os
import time
import yaml
import requests

from commit import commit
from pathlib import Path
from datatypes import Submission
from datetime import datetime
from bs4 import BeautifulSoup

CONFIG_PATH = "config.yml"
PROBLEMS_API_ENDPOINT = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"

class AtCoderSubmissionsArchiver():
    def __init__(self):
        self.load_config()

    def load_config(self) -> dict:
        with open(CONFIG_PATH, "r", encoding="UTF-8") as f:
            self.config = yaml.safe_load(f)
        atcoder = self.config["atcoder"]
        self.extensions = self.config["extensions"]
        self.user_id = atcoder["user_id"]
        self.last_update = atcoder["last_update"] + 1

    def update_config(self) -> None:
        self.config["atcoder"]["last_update"] = self.last_update
        with open(CONFIG_PATH, "w", encoding="UTF-8") as f:
            yaml.safe_dump(self.config, f, default_flow_style=False, sort_keys=False)

    def get_extension(self, lang: str) -> str:
        for v in self.extensions:
            if lang.startswith(v):
                return self.extensions[v]
        return "unknown"

    def fetch_submissions(self, fetchAll=False) -> list[Submission]:
        epoch_sec = self.last_update
        if fetchAll:
            epoch_sec = 0
            print("Fetch all submissions...")
        params = { "user": self.user_id, "from_second": epoch_sec }
        result = requests.get(url=PROBLEMS_API_ENDPOINT, params=params)
        return [Submission(**s) for s in result.json()]

    def fetch_code(self, s: Submission) -> str:
        submission_url = f"https://atcoder.jp/contests/{s.contest_id}/submissions/{s.id}"
        result = requests.get(submission_url).text
        soup = BeautifulSoup(result, "html.parser")
        code = soup.select_one("pre#submission-code")
        if code is None:
            print("code not found for", s.id)
            print(f"\033[91mCode not found for {s.id}\033[0m")
            self.unfound_codes.append(s)
            return "// code not found"
        return code.text.replace("\r", "")
    
    def write_code(self, s: Submission, code: str) -> None:
        save_extension = self.get_extension(s.language)
        save_dir = os.path.join(Path(os.path.dirname(__file__)).parent, "AtCoder", s.contest_id)
        save_path = f"{save_dir}{os.sep}{s.problem_id}.{save_extension}"
        os.makedirs(save_dir, exist_ok=True)
        with open(save_path, "w", encoding="UTF-8") as f:
            f.write(code)
    
    def commit_code(self, s: Submission) -> None:
        save_extension = self.get_extension(s.language)
        save_dir = os.path.join(Path(os.path.dirname(__file__)).parent, "AtCoder", s.contest_id)
        save_path = f"{save_dir}{os.sep}{s.problem_id}.{save_extension}"
        commit(s, save_path)

    def __call__(self):
        print("Last update time:", datetime.fromtimestamp(self.last_update))
        submissions = self.fetch_submissions()
        print("Found {} submission(s)".format(len(submissions)))
        cnt = 1
        for record in submissions:
            print(f"\r\033[1m ({cnt: 3}/{len(submissions): 3})\033[0m Submission #{record.id} ({record.problem_id}, at {datetime.fromtimestamp(record.epoch_second)})", end="", flush=True)
            if record.result == "AC":
                code = self.fetch_code(record)
    #           self.write_code_and_commit(s=record, code=code)
    #           self.commit_code(s=record)
                print("\033[2K\033[G", end="")
                print(f"\r\033[92mDone\033[0m\t{record.contest_id}/{record.problem_id}: #{record.id} at {datetime.fromtimestamp(record.epoch_second)}", flush=True)
            else:
                print("\033[2K\033[G", end="")
                print(f"\r\033[93m[{record.result}]\033[0m\t{record.contest_id}/{record.problem_id}: #{record.id} at {datetime.fromtimestamp(record.epoch_second)}", flush=True)
            cnt += 1
            self.last_update = record.epoch_second
        for unfound_code in unfound_codes:
            submission_url = f"https://atcoder.jp/contests/{s.contest_id}/submissions/{s.id}"
            print(f"\033[1;37;43m Warn \033[0m Code #{s.id} could not be fetched. ({submmission_url})")
        self.update_config()
        print("\033[1;37;42m ALL DONE! \033[0m")

if __name__ == "__main__":
    AtCoderSubmissionsArchiver()()
