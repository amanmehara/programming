object CreateList {

  //A list with 4 items
  val numberList = "One" :: "Two" :: "Three" :: "Four" :: Nil

  def main(args: Array[String]): Unit = {
    //Print all 4 items of the list
    numberList.foreach((x: Any) => println(x))
  }

}