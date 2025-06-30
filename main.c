#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 1000
#define N 100

const char *readline()
{
    static char buffer[NMAX + 1];
    fgets (buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    return buffer;
}

void in_op(const char *line, char *op)
{
    strcpy(op, &line[3]);
}

void out_range(const char *sp, const char *ep)
{
    //printf("%p %p\n", sp, ep);

    while (sp != ep){
        printf("%c", sp[0]);
        sp++;
    }
    printf("\n");
}

int move_sp(char* num)
{
    int i_num = atoi(num);
    return i_num;
}

void najdi_prve(char* op, int len, int* z, int* k)
{
    *z = 0;
    *k = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalnum(op[i]) != 0)
        {
            *z = i;
            for (int j = i; j <= len; j++)
            {
                if (isalnum(op[j]) == 0)
                {
                    *k = j;
                    break;
                }
            }
            break;
        }
    }
}

void najdi_posledne(char* op, int len, int* z, int* k)
{
    *z = len;
    *k = len;

    for (int i = len-1; i >= 0; i--)
    {
        if (isalnum(op[i]) != 0)
        {
            *k = i+1;
            for (int j = i; j >= 0; j--)
            {
                if (isalnum(op[j]) == 0)
                {
                    *z = j+1;
                    break;
                }

                if (j == 0)
                {
                    *z = j;
                    break;
                }
            }
            break;
        }
    }

}

int najdi_dalsie_zaciatok(char* op, int len, char* sp)
{
    char *sp_a = sp;
    int pocitadlo = 0;

    while (isalnum(sp_a[0]) != 0)
    {
        sp_a++;
        pocitadlo++;
        if (sp_a == &op[len])
        {
            break;
        }
    }

    while (isalnum(sp_a[0]) == 0)
    {
        sp_a++;
        pocitadlo++;
        if (sp_a == &op[len])
        {
            break;
        }
    }

    return pocitadlo;
}

int najdi_dalsie_koniec(char* op, int len, char* ep)
{
    char *ep_a = ep;
    int pocitadlo = 0;

    while (isalnum(ep_a[0]) != 0)
    {
        pocitadlo++;
        ep_a++;
        if (ep_a == &op[len])
        {
            break;
        }
    }

    return pocitadlo;
}

int najdi_predosle_zaciatok(char* op, char* sp)
{
    char *sp_a = sp;
    int pocitadlo = 0;

    while (isalnum(sp_a[0]) != 0)
    {
        sp_a--;
        pocitadlo++;
        if (sp_a == &op[0])
        {
            return pocitadlo;
        }
    }

    while (isalnum(sp_a[0]) == 0)
    {
        sp_a--;
        pocitadlo++;
        if (sp_a == &op[0])
        {
            return pocitadlo;
        }
    }

    while (isalnum(sp_a[0]) != 0)
    {
        sp_a--;
        pocitadlo++;
        if (sp_a == &op[0])
        {
            return pocitadlo;
        }
    }

    return pocitadlo-1;
}

char del(char* op, char* sp, char* ep, int dlzka_range)
{
    int len = strlen(op);
    char op_a[len];
    int pocitadlo = 0;

    while (&op[pocitadlo] != sp)
    {
        op_a[pocitadlo] = op[pocitadlo];
        pocitadlo++;
    }

    while (ep[0] != op[len])
    {
        op_a[pocitadlo] = ep[0];
        pocitadlo++;
        ep++;
    }
    op_a[pocitadlo] = '\0';

    strcpy(op, op_a);
}

int dlzka_substringu(char* sp, char* ep)
{
    int dlzka = 0;

    while (sp != ep){
        sp++;
        dlzka++;
    }
    return dlzka+1;
}

void crop(char* op, char* sp, char* ep)
{
    int pocitadlo = 0;
    int len = strlen(op);
    char op_a[len];
    op_a[0] = '\0';

    while (sp != ep)
    {
        op_a[pocitadlo] = sp[0];
        sp++;
        pocitadlo++;
    }
    op_a[pocitadlo] = '\0';
    strcpy(op, op_a);
}

void insert_mem(char* op, char* mem, char* sp)
{
    int i = 0;
    int len_mem = strlen(mem);
    int len_op = strlen(op);
    char op_a[len_mem + len_op];
    op_a[0] = '\0';

    while (&op[i] != sp)
    {
        op_a[i] = op[i];
        i++;
    }

    int z = i;
    int j = 0;
    while (j != len_mem)
    {
        op_a[z] = mem[j];
        j++;
        z++;
    }

    while (i != len_op)
    {
        op_a[z] = op[i];
        i++;
        z++;
    }
    op_a[z] = '\0';
    strcpy(op, op_a);

}

void replace(char* op, char* mem, char* sp, char* ep)
{
    int i = 0;
    int len_op = strlen(op);
    int len_mem = strlen(mem);
    char op_a[N+1];
    op_a[0] = '\0';
    int range = ep - sp;
    int insert_len = (len_mem < range) ? len_mem : range;
    /*printf("op: : %s\n", op);
    printf("sp: %s\n", sp);
    printf("mem: %s\n", mem);
    printf("ep: %s\n", ep);*/
    while (&op[i] != sp)
    {
        op_a[i] = op[i];
        i++;
    }

    int j = 0;
    while (j != len_mem)
    {
        op_a[i] = mem[j];
        i++;
        j++;

        if (&op[i] == ep)
        {
            break;
        }
    }

    while (i != len_op)
    {
        op_a[i] = op[i];
        i++;
    }

    // Vlož len časť z mem
    /*for (; j < insert_len; j++, i++) {
        op_a[i] = mem[j];
    }

    // Pokračuj po ep
    int k = ep - op;
    while (op[k] != '\0') {
        op_a[i] = op[k];
        i++; k++;
    }*/

    op_a[i] = '\0';
    strcpy(op, op_a);
}

int main(void)
{
    char op[N+1], mem[N+1];
    op[0] = '\0'; mem[0] = '\0';
    char *sp = &op[0];
    char *ep = &op[0];
    int len = strlen(op);

    const char *line = readline();
    while (strcmp(line, "quit") != 0)
    {
        if (strncmp(line, "in ", 3) == 0)
        {
            len = strlen(&line[3]);
            if (len > N)
            {
                printf("ERR_OVERFLOW");
                return 0;
            }

            in_op(line, op);
            len = strlen(op);
            ep = &op[len];
        }

        else if (strcmp(line, "out op") == 0)
        {
            printf("%s\n",op);
        }

        else if (strcmp(line, "out range") == 0)
        {
            out_range(sp, ep);
        }

        else if (strcmp(line, "out mem") == 0)
        {
            printf("%s\n", mem);
        }

        else if (strncmp(line, "move sp ", 8) == 0)
        {
            char num[10];
            strcpy(num, &line[8]);
            int i_num = move_sp(num);
            sp += i_num;
            if (sp < &op[0] || sp > &op[len])
            {
                printf("ERR_OUT_OF_RANGE\n");
                return 0;
            }

        }

        else if (strncmp(line, "move ep ", 8) == 0)
        {
            char num[10];
            strcpy(num, &line[8]);
            int i_num = move_sp(num);
            ep += i_num;
            if (ep < &op[0] || ep > &op[len])
            {
                printf("ERR_OUT_OF_RANGE\n");
                return 0;
            }
        }

        else if (strncmp(line, "start sp", 7) == 0)
        {
            sp = &op[0];
        }

        else if (strncmp(line, "start ep", 7) == 0)
        {
            ep = &op[0];
        }

        else if (strncmp(line, "end sp", 7) == 0)
        {
            sp = &op[len];
        }

        else if (strncmp(line, "end ep", 7) == 0)
        {
            ep = &op[len];
        }

        else if (strcmp(line, "first") == 0)
        {
            int z, k;
            najdi_prve(op, len, &z, &k);
            sp = &op[z];
            ep = &op[k];
        }

        else if (strcmp(line, "last") == 0)
        {
            int z, k;
            najdi_posledne(op, len, &z, &k);
            sp = &op[z];
            ep = &op[k];
        }

        else if (strcmp(line, "next") == 0)
        {
            sp+=najdi_dalsie_zaciatok(op, len, sp);
            ep = sp;
            ep+=najdi_dalsie_koniec(op, len, ep);
        }

        else if (strcmp(line, "prev") == 0)
        {
            if (sp[0] != op[0])
            {
                sp-=najdi_predosle_zaciatok(op, sp);
                ep = sp;
                ep+=najdi_dalsie_koniec(op, len, ep);
            }

            else
            {
                ep = sp;
            }

        }

        else if (strcmp(line, "del") == 0)
        {
            if (sp > ep)
            {
                printf("ERR_POSITION");
                return 0;
            }

            char *sp_temp = sp;
            char *ep_temp = ep;
            sp = ep;
            int dlzka_range = dlzka_substringu(sp_temp, ep_temp);
            del(op, sp_temp, ep_temp, dlzka_range);
            sp = sp - dlzka_range + 1;
            ep = ep - dlzka_range + 1;
        }

        else if (strcmp(line, "crop") == 0)
        {
            if (sp > ep)
            {
                printf("ERR_POSITION");
                return 0;
            }

            crop(op, sp, ep);
            len = strlen(op);
            sp = &op[0];
            ep = &op[len];
        }

        else if (strcmp(line, "copy") == 0)
        {
            if (sp > ep)
            {
                printf("ERR_POSITION");
                return 0;
            }

            strcpy(mem, op);
            crop(mem, sp, ep);
        }

        else if (strncmp(line, "insert ", 6) == 0)
        {
            if (sp > ep)
            {
                printf("ERR_POSITION");
                return 0;
            }
            int len_op = strlen(op);

            if (strncmp(line, "insert mem", 9) == 0)
            {
                int len_mem = strlen(mem);

                if (len_mem + len_op >= N)
                {
                    printf("ERR_OVERFLOW");
                    return 0;
                }
                insert_mem(op, mem, sp);
                ep = ep + len_mem;

            }

            else
            {
                char num[10];
                strcpy(num, &line[7]);
                int i_num = move_sp(num);

                if (len_op + i_num >= N)
                {
                    printf("ERR_OVERFLOW");
                    return 0;
                }

                char empty_mem[i_num];
                for (int i = 0; i < i_num; i++)
                {
                    empty_mem[i] = ' ';
                }

                empty_mem[i_num] = '\0';
                int len_mem = strlen(empty_mem);
                insert_mem(op, empty_mem, sp);
                ep = ep + len_mem;
            }
        }

        else if (strcmp(line, "replace") == 0)
        {
            if (sp > ep)
            {
                printf("ERR_POSITION");
                return 0;
            }

            if (mem[0] != '\0' && sp != ep)
            {
                replace(op, mem, sp, ep);
            }

        }

        len = strlen(op);
        line = readline();
    }

    return 0;
}