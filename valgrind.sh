g++ LinkedList.h Node.h Main.cpp -o LinkedList -std=c++11
valgrind --leak-check=full ./LinkedList
rm LinkedList