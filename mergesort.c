
void mergesort(A, i, j){
  if (i>=j)
    return;
  else{
    mid = (i+j)/2;
    mergesort(A, i, mid); //recursively call mergesort
    mergesort(A, mid+1, j);
    merge(A, i, j, mid);
  }
}

void merge(A, i, j, mid){
  int k = mid+1;
  int b[], l, start;
  l = i;
  start = i;

  while(i<=mid && k<=j){ //loop until either of the array reaches the end
    if (A[i] <= A[k])
      b[l++] = A[i++];
    else
      b[l++] = A[k++];
  }

  if (i>mid){  //if either of the array reaches its end, directly copy the rest of the element into the main array
    while(k<=j) b[l++] = A[k++];
  }
  else if(k>j){
    while(i<=mid) b[l++] = A[i++];
  }

  for (l = start; l<=j;l++)
    b[l] = a[l];
  return;
}
