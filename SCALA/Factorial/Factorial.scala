/**
  * Created by @amanmehara on 24-09-2017.
  */
object Factorial {

  def factorial (number: Int, accumulator: BigInt = 1): BigInt = {
    if(number > 0) factorial(number - 1, accumulator * number) else accumulator
  }

}
