/**
 * Created by @amanmehara on 24-09-2017.
 */

/**
 * We can force a number (including binary, octals and hexadecimals) to have a specific type by giving a suffix, either uppercase or lowercase.
 *
 * BigInteger -> G or g
 * Long       -> L or l
 * Integer    -> I or i
 * BigDecimal -> G or g
 * Double     -> D or d
 * Float      -> F or f
 *
 */

assert 42I == new Integer('42')
assert 42i == new Integer('42') // lowercase i more readable
assert 123L == new Long("123") // uppercase L more readable
assert 2147483648 == new Long('2147483648') // Long type used, value too large for an Integer
assert 456G == new BigInteger('456')
assert 456g == new BigInteger('456')
assert 123.45 == new BigDecimal('123.45') // default BigDecimal type used
assert 1.200065D == new Double('1.200065')
assert 1.234F == new Float('1.234')
assert 1.23E23D == new Double('1.23E23')
assert 0b1111L.class == Long // binary
assert 0xFFi.class == Integer // hexadecimal
assert 034G.class == BigInteger // octal