#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cars.h"

int compare_cars_direct(const Car *a, const Car *b, int field, int descending) {
    int result = 0;
    if (field == 0) {
        result = strcmp(a->brand, b->brand);
    } else if (field == 1) {
        result = strcmp(a->owner, b->owner);
    } else if (field == 2) {
        if (a->mileage < b->mileage) result = -1;
        else if (a->mileage > b->mileage) result = 1;
    }

    return descending ? -result : result;
}
int cmp_qsort(const void *a, const void *b, void *arg) {
    const Car *carA = a;
    const Car *carB = b;
    int *args = (int *)arg; // args[0] = field(0,1,2), args[1] = descending(0,1,2)
    return compare_cars_direct(carA, carB, args[0], args[1]);
}

int gnome_sort(Car *cars, int count, int field, int asc) {
   int i = 0;
    while (i < count) {
        if (i == 0 || compare_cars_direct(&cars[i - 1], &cars[i], field, asc) <= 0) {
            i++;
        } else {
            Car temp = cars[i];
            cars[i] = cars[i - 1];
            cars[i - 1] = temp;
            i--;
        }
    }
}

int insertion_sort(Car *cars, int count, int field, int asc) {
    for (int i = 1; i < count; i++) {
        Car key = cars[i];
        int j = i - 1;
        while (j >= 0 && compare_cars_direct(&cars[j], &key, field, asc) > 0) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = key;
    }
}

int sort(Car *cars, int count, int sortAlgo, int field, int asc) {
  switch(sortAlgo) {
    case 0:
      gnome_sort(cars, count, field, asc);
      break;
    case 1:
      insertion_sort(cars, count, field, asc);
      break;
    case 2:
      int args[2] = {field, asc};
      qsort_r(cars, count, sizeof(Car), cmp_qsort, args);
      break;
    default:
      break;
  }
}