/**
  * Created by @amanmehara on 24-09-2017.
  */
object SequenceSumByReduction {

  def sumByReduction (numbers: List[Int]): Int = {
    numbers.reduceLeft(_ + _)
  }

}
