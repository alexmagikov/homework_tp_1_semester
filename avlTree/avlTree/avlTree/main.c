#include "dictionary.h"
#include <stdlib.h>

int main() {
    Dictionary* dictionary = NULL;
    insert(&dictionary, "1", "value1", 0);
    insert(&dictionary, "2", "value2", 0);
    insert(&dictionary, "3", "value3", 0);
    //insert(&dictionary, "3", "value3", 0);
    //insert(&dictionary, "5", "value3", 0);
    return 0;
}