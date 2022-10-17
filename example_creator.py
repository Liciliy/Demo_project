

import random
import string
from random import randrange

number_of_examples = 10000000


def get_bool():
    bool_vars = ["true", "false"]
    pos = randrange(2)

    return bool_vars[pos]

def get_number():
    return str(randrange(2000))

def get_str():
    return f"\"{''.join(random.choice(string.ascii_lowercase) for i in range(4))}\""



if __name__ == "__main__":

    json_generated_example = "json_gen_example.txt"
    with open(json_generated_example, 'w') as output_file:

        vals_creators = [get_bool, get_number, get_str]

        add_nl = False


        for key_id in range(number_of_examples):

            
            key = ''.join(random.choice(string.ascii_lowercase) for i in range(4))
            key1 = f'{key}_{randrange(2000)}'
            val1 = vals_creators[randrange(3)]()

            key = ''.join(random.choice(string.ascii_lowercase) for i in range(4))
            key2 = f'{key}_{randrange(2000)}'
            val2 = vals_creators[randrange(3)]()

            key = ''.join(random.choice(string.ascii_lowercase) for i in range(4))
            key3 = f'{key}_{randrange(2000)}'
            val3 = vals_creators[randrange(3)]()

            res = "{" + f'"{key1}":{val1}, "{key2}":{val2}, "{key3}":{val3}' + "}"

            if add_nl is False:
                add_nl = True
            else:
                res = f'\n{res}'

            output_file.write(res)