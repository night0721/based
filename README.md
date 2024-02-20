# based

based is a command line tool to help A level students to revise base conversion.

## Preview
![](https://r2.e-z.host/3c62bb3a-a8a9-43f6-afd6-553646f51dc4/8px2rilw.png)

## Dependencies
- gcc

## Building
```sh
$ make
$ sudo make install
```

## Usage
```
Usage: ./based -f [from] -t [to] -n [number]
based is a command line tool to help A level students to revise base conversion.
Options:
    -f [bin|oct|dec|hex]    The base to convert from
    -t [bin|oct|dec|hex]    The base to convert to
    -n [number]             The number to convert (must be representable by 8 bits)
                            When from base is binary, the number must have 8 characters
                            When from base is octal, the number must have at most 3 characters
                            When from base is hexadecimal, the number must have 2 characters
                            When from base is decimal, the number must be a bigger than 0 and smaller than 256
```

# Contributions
Contributions are welcomed, feel free to open a pull request.

# License
This project is licensed under the GNU Public License v3.0. See [LICENSE](https://github.com/night0721/based/blob/master/LICENSE) for more information.
