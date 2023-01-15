function solution(A, K) {
  let count = 0;
  A.sort((a, b) => a - b);

  while (A.length > 0) {
    for (let i = A.length - 1; i >= 0; i--) {
      if (A[0] + A[i] <= K) {
        count++;
        A.splice(i, 1);
        A.splice(0, 1);
        break;
      } else {
        count++;
        A.splice(i, 1);
      }
    }
  }
  return count;
}
