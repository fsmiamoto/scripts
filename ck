#/bin/sh
# Checkout to a given branch or create it if it does not exist
# github.com/fsmiamoto

# Check if we're in a git repo
git rev-parse --is-inside-work-tree > /dev/null 2>&1
[ "$?" != "0" ] && exit 1;

branch=$(git branch -v | rg -v '\*' | fzf --preview-window=hidden --print-query | tail -1 | awk '{ print $1 }')

# Check if branch exists
git show-branch "$branch" &>/dev/null

if [ "$?" != "0" ]; then
    echo "Creating new branch: $branch"
    git branch "$branch"
fi

git checkout "$branch"
unset branch
exit 0

