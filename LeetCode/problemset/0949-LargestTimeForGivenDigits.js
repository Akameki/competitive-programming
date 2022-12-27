/**
 * @param {number[]} arr
 * @return {string}
 */
var largestTimeFromDigits = function (arr) {

  arr.sort((a, b) => b - a);
  temp = [...arr]
  ans = [];
  let d = popUpTo(arr, 2);
  ans.push(d);
  if (d == 2) {
    ans.push(popUpTo(arr, 3));
  } else {
    ans.push(popUpTo(arr, 9));
  }
  ans.push(popUpTo(arr, 5));
  ans.push(popUpTo(arr, 9));
  if (!ans.includes(-1)) return "" + ans[0] + ans[1] + ":" + ans[2] + ans[3];

  arr = [...temp]
  ans = [];
  ans.push(popUpTo(arr, 1));
  ans.push(popUpTo(arr, 9));
  ans.push(popUpTo(arr, 5));
  ans.push(popUpTo(arr, 9));
  if (!ans.includes(-1)) return "" + ans[0] + ans[1] + ":" + ans[2] + ans[3];

  return "";

};


// return int
function popUpTo(arr, n) {
  for (let i = 0; i < 4; i++) {
    if (arr[i] <= n) {
      ret = Number(arr[i]);
      arr[i] = 99;
      return ret;
    }
  }
  return -1;
}