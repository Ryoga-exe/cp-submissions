import git
from datetime import datetime

from datatypes import Submission

def commit(s: Submission, path: str) -> None:
    repo = git.Repo(".")
    repo.git.add(path)
    commit_message = f"[AtCoder] archive: {s.contest_id}/{s.problem_id} #{s.id}"
    try:
        repo.git.commit("-m", commit_message)
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[1;37;41m Fail \033[0m Failed to commit: {commit_msg}", flush=True)
        print(err)
        if "Your branch is up to date with 'origin/main'." in err.stdout:
            print("Nothing to commit, skipping...")
            return
        exit(1)
    try:
        repo.git.rebase("HEAD~1", "--committer-date-is-author-date")
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[1;37;41m Fail \033[0m Failed to rebase: {commit_msg}", flush=True)
        print(err)
        exit(1)
