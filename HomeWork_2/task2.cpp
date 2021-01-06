#include <iostream>

void toUpperCase(char &letter);
void replaceDigit(char *arr, int pos, int &size);
void readArray (char *arr);
int getSize(char *arr);
void removeWord(char *text, size_t &sizeText, char *word);
void removeElement(char *array, size_t &size, const size_t &index);
void insert(char *arr,const int &pos, size_t &size,const char element);
void print(const char *arr, size_t &size);




int main() {

  char *str = new char[1000];
    readArray(str);
    size_t length = getSize(str);

    char word[7] = "visoko";
        removeWord(str, length, word);

for(size_t i = 0; i < length; i++)
{
  if((str[i] == '4' || str[i] == '6') && (str[i-1] != ' ' || str[i+1] != ' ')) {
    insert(str, i + 1, length, 'h');
    str[i] == '4' ? str[i] = 'c' : str[i] = 's';
  }
  if((str[i-1] >= 'a' && str[i-1] <= 'z') && (str[i] == '.' || str[i] == '!' || str[i] == ':' || str[i] == '?'))
  {
    toUpperCase(str[i + 1]);
  }
}

print(str, length);

// V bavisokozata na OON e otkrita vvisokoun6na namesa. trqbva nezvisokoabavno da suob6tim za srevisokoshtata v 4 na vsvisokoeki 4ovek ot otvisokodela!

  return 0;
}

void readArray(char *arr)
{
  std::cin.getline(arr, 1000);
}

void print(const char *arr, size_t &size) {
  for(int i = 0; i < size; i++)
    std::cout <<arr[i];
}

void insert(char *arr, const int &pos, size_t &size, const char element) {
  for (size_t i = size; i > pos; i--) {
       arr[i] = arr[i - 1];
   }
   arr[pos] = element;
   size++;
}

void toUpperCase(char &letter) {
        if (letter >= 'a' && letter <= 'z')
                letter = letter - ('a' - 'A');
}

int getSize(char *arr) {
  int length = 0;
  while(arr[length] != '\0')
  {
    length++;
  }
  return length;
}

void removeWord(char *text, size_t &sizeText, char *word) {
    int sizeWord = getSize(word);
    int *startIndex = new int[1000];
    int i = 0;
    bool flag = false;
    for (int indexText = 0; indexText < sizeText; indexText++) {
        flag = true;
        if (text[indexText] == word[0] && text[indexText - 1] != ' ' && text[indexText + 1] != ' ') {
            for (int indexWord = 0; indexWord < sizeWord; indexWord++) {
                if (text[indexText] != word[indexWord]) {
                    flag = false;
                    break;
                }
                indexText++;
            }
            if (flag) {
                startIndex[i] = indexText - sizeWord;
                i++;
            }
        }
    }

    for (unsigned j = 0; j < i; j++) {
        for (unsigned i = 0; i < sizeWord; i++) {
            removeElement(text,sizeText,startIndex[j]);
        }
        if (j != i - 1) {
            startIndex[j + 1] = startIndex[j + 1] - sizeWord*(j + 1);
        }
    }
    delete[] startIndex;
}

void removeElement(char *array, size_t &size, const size_t &index) {
    for (size_t i = index; i < size; i++) {
        array[i] = array[i + 1];
    }
    size--;
}
