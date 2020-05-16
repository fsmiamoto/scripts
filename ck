#/bin/sh
# Checkout to a given branch or create it if it does not exist
# github.com/fsmiamoto

# Check if we're in a git repo
git rev-parse --is-inside-work-tree > /dev/null 2>&1
[ "$?" != "0" ] && exit 1;

selection=$(git branch -v | rg -v '\*' | fzf --prompt="Checkout: " --preview-window=hidden --print-query)

branch=$(echo "$selection" | tail -1 | awk '{ print $1 }')

# Nothing selected
[ "$branch" =  "" ] && exit

# Check if branch exists
git show-branch "$branch" &>/dev/null

if [ "$?" != "0" ]; then
    echo "Creating new branch: $branch"
    git branch "$branch"
fi

git checkout "$branch"
unset branch

[ "$1" = "-w" ] && read

exit 0

