# 将 DELETE_KOKEN 和 GithubName 都替换为自己的
DELETE_KOKEN="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"
GithubName="If-only1"

for repName in $(cat repos.txt)
do
    echo "Delete "$repName
    curl -XDELETE -H "Authorization: token ${DELETE_KOKEN}" https://api.github.com/repos/${GithubName}/${repName}
done