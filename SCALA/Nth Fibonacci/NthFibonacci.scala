object NthFibonacci {

  def nthFibonacci(number: Int, x: BigInt = 0, y: BigInt = 1): BigInt = number match {
    case 0 => x
    case 1 => y
    case _ => nthFibonacci(number - 1, y, x + y)
  }

}