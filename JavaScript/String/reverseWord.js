const ReverseWord = (str) => {
  //this will check if the input is a string or not
  //if not we'll just return 'Not a number'
  if (typeof str !== "string") {
    return "Not a String";
  }
  //if the input is string we're gonna do this algorithm
  //we check if the string is empty or not
  //if the string is empty we're just gonna return 'empty string'
  if (str.length === 0) {
    return "Empty String";
  }
  //if the string is not an empty string we're gonna do this algorithm
  //we split the string into substring and turn them into array using .split method
  const strArr = str.split("");
  //then we reverse the elements of the strArr using .reverse method
  const reverseArr = strArr.reverse();
  //and lastly we return the concatenated value of the reverseArr using the .join method to make it string again
  return reverseArr.join("");
};
console.log(ReverseWord("koddi"));
