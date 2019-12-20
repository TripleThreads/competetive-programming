def least_square():
    n, m, a = input().split(" ")
    n = int(n)
    m = int(m)
    a = int(a)

    if n <= a and m <= a:
        print(1)

    elif n <= a and m != a:
        n_a = 0

        m_a = m // a + (1 if m % a else 0)

        print(n_a + m_a)

    elif m <= a and n != a:

        n_a = 0

        m_a = n // a + (1 if n % a else 0)

        print(n_a + m_a)

    else:
        n_a = n // a + (1 if n % a else 0)

        m_a = m // a + (1 if m % a else 0)

        print(n_a * m_a)


least_square()