#include "src.h"
#include <assert.h>

using namespace std;

void test(Map<string, string>* Word)
{
    Map<string, string>::iterator it;
    it = Word->begin();
    assert(4 == it.GetAmount());
    it++;
    assert(3 == it.GetAmount());
}

int main()
{
    Map<string, string> word;
    string exWord = "Floppa";
    word.insert(exWord, exWord);
    word.insert(exWord, exWord);
    word.insert(exWord, exWord);
    exWord = "Fanter";
    word.insert(exWord, exWord);
    word.insert(exWord, exWord);
    word.insert(exWord, exWord);
    word.insert(exWord, exWord);
    test(&word);
	return 0;
}