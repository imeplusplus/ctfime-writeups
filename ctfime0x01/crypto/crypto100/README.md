![crypto100](../../_images/crypto100)

EXTRAIR ARQUIVO

Visualmente (e com a dica!) é evidente que o conteúdo do arquivo de texto é output do hexdump de um arquivo. Para interpretarmos esse conteúdo como caracteres ASCII, precisamos:

- Remover a primeira coluna (offset)
- Remover todos os espaços em branco e quebras de linha
- Inverter a ordem dos bytes 2 a 2

Para removermos os offsets que o hexdump insere, basta utilizarmos o sed para remover os primeiros 8 caracteres de cada linha e redirecionarmos o output para um novo arquivo:

    sed 's/^........//' flag > flag2

Como a última linha possui apenas o offset (sem o espaço à direita), removemos também a última linha. O comando completo seria:

    sed 's/^........//' flag | sed '$d' > flag2
    cat flag2
    c348 20a1 616d 7369 6320 696f 6173 2073
    6e65 7274 2065 206f c363 75a9 6520 6120
    7420 7265 6172 6420 206f 7571 2065 6f70
    6564 6920 616d 6967 616e 2072 6f6e 7373
    2061 c376 20a3 6966 6f6c 6f73 6966 2e61
    430a 4654 4d49 7b45 316c 756e 5f35 3074
    7672 6c34 3564 0a7d

Para removermos os espaços e as quebras de linha

    cat flag2 | tr -d " \t\n\r" > flag3
    cat flag3
    c34820a1616d73696320696f617320736e6572742065206fc36375a9652061207420726561726420206f757120656f7065646920616d6967616e20726f6e73732061c37620a369666f6c6f7369662e61430a46544d497b45316c756e5f35307476726c3435640a7d

O hexdump produz por default o output em palavras de 16 bits de acordo com a arquitetura do computador. Assim, se a arquitetura é *little endian*, o resultado do hexdump será que as palavras de 16 bits estarão "invertidas". De fato, se tentarmos converter essa string em hexa para ASCII (abra o interpretador python):

    >>> str="c34820a1616d73696320696f617320736e6572742065206fc36375a9652061207420726561726420206f757120656f7065646920616d6967616e20726f6e73732061c37620a369666f6c6f7369662e61430a46544d497b45316c756e5f35307476726c3435640a7d"
    >>> str.decode("hex")
    '\xc3H \xa1amsic ioas snert e o\xc3cu\xa9e a t reard  ouq eopedi amigan ronss a\xc3v     \xa3ifolosif.aC\nFTMI{E1lun_50tvrl45d\n}'

Para garantirmos quantos bytes possui cada caractere basta verificarmos o *encoding*:

    file -bi flag
    text/plain; charset=us-ascii

Como o ASCII codifica cada caractere como 1 byte e o hexdump está imprimindo palavras de 16 bits (2 bytes), precisamos inverter os bytes 2 a 2.


Flag: *CTFIME{l1nu5_t0rv4ld5}*

