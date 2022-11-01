

echo "Starting Setup"

mkdir "build"

cd "build"

cmake --clean-first ..

make

sh "run.sh"