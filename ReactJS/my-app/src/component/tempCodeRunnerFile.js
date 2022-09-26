const twoSum = (arr, target) => {
  if (!Array.isArray(arr)) return false;

  let newArr = [];
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[i] + arr[j] === target) {
        newArr.push(i);
        newArr.push(j);
      }
    }
  }

  return newArr;
};

console.log(twoSum([3, 2, 4], 6));
