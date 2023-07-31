# the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile; the second argument 
#is a text string which will be written within this file, referred to below as writestr

if [ $# -lt 2 ]
then
    echo "more args needed"
    exit 1
fi

path=$1
tail="${path#*/*/*/}"
head="${path%$tail}"
echo "$head" "$tail"

mkdir -p ${head} 
echo "$2" > $1

#touch "$2" > $1