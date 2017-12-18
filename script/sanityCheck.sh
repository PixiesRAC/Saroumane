if [ ! -d "../log" ];then
echo "Log folder not present, creation of it";
mkdir ../log
fi

if [ ! -d "../third_party/googletest" ];then
echo "googletest folder not present, creation of it";
mkdir ../third_party
cd ../third_party/.
git clone https://github.com/google/googletest.git
cd googletest
cmake .
fi

