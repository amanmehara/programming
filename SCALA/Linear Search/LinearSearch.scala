object LinearSearch {

  def linearSearch[A](numbers: List[A], key: A): Option[A] = {
    def search(numbers: List[A]): Option[A] =
      if (numbers.isEmpty) None
      else if (numbers.head == key) Option(numbers.head)
      else search(numbers.tail)

    search(numbers)
  }

}