// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count1++;
      }
    }
  }
  return count1;
}
int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        count2++;
      }
    }
  }
  return count2;
}
int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  for (int i = 0; i < len - 1; i++) {
    int rig = len, lef = i;
    while (rig - 1 > lef) {
      int mids = (lef + rig) / 2;
      if (arr[i] + arr[mids] == value) {
        count3++;
        int midd = mids + 1;
        while (arr[i] + arr[midd] == value && midd < rig) {
          count3++;
          midd++;
        }
        midd = mids - 1;
        while (arr[i] + arr[midd] == value && midd > lef) {
          count3++;
          midd--;
        }
        break;
      }
       if (arr[i] + arr[mids] > value) {
        rig = mids;
      } else {
        lef = mids;
      }
    }
  }
  return count3;
}
