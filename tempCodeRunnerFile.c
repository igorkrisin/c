char str[10000];
    char* str_new;
    printf("введите вырaжение: ");
    fgets(str, 10000, stdin);
    str_new = stripr_el(str);
    print_list(calc(split(str_new)));