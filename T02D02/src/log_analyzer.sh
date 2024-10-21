filePath=$1

if [ -e $filePath ]; then
num=$(wc -l $filePath | awk '{print $1}')
numUnique=$(cat $filePath | awk '{print $1}' | uniq | wc -l)
numChange=$(($(cat $filePath | awk '{print $8}' | uniq | wc -l)-1))

echo $num $numUnique $numChange

else
echo "ERROR! FILE NOT FOUNDED"
fi
