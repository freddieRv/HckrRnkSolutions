def flippingBits(n):
    n_bin = bin(n)[2:]
    fliped_str = ''

    for bit in n_bin:
        fliped_str += str(int(not int(bit)))

    leading_ones = '1' * (32 - len(n_bin))

    return int(leading_ones + fliped_str, 2)

if __name__ == '__main__':
    print(flippingBits(0))
