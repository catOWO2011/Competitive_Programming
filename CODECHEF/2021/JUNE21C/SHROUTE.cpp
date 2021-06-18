#include <iostream>
#include <vector>
#include <cmath>

// #include <fstream>

using vector = std::vector<int>;

/*
3
5 1
1 0 0 0 0
5
5 1
1 0 0 0 2
4
5 2
2 0 0 0 1
3 1

1
10 4
0 1 2 1 0 0 0 0 2 1
8 1 3 2

1
5 3
1 0 0 2 1
1 2 3

1
5 1
0 0 0 0 2
2


**/

// std::ofstream out("out.txt");

void print_minimum_time_required(vector& cities, vector& destinations) {
  vector c(cities.size(), -1);
  int lastRightTrain = -1;
  int lastLeftTrain = -1;
  int trainOriginating;

  for (size_t left = 0; left < cities.size(); left++)
  {
    trainOriginating = cities[left];
    if (trainOriginating == 0)
    {
      if (lastLeftTrain > -1)
      {
        c[left] = abs(left - lastLeftTrain);
      }
    }
    else if(trainOriginating == 1)
    {
      c[left] = 0;
      lastLeftTrain = left;
    }
  }

  for (int right = cities.size() - 1; right > -1; right--)
  {
    // std::cout << right << " RIGHT\n";
    trainOriginating = cities[right];
    if (trainOriginating == 0)
    {
      if (lastRightTrain > -1)
      {
        if (c[right] != -1)
        {
          c[right] = std::min(abs(lastRightTrain - right), c[right]);
        } else {
          c[right] = abs(lastRightTrain - right);
        }
      }
    }
    else if(trainOriginating == 2)
    {
      c[right] = 0;
      lastRightTrain = right;
    }
  }

  for (size_t i = 0; i < destinations.size(); i++)
  {
    if (i > 0) {
      printf(" ");
      // out << " ";
    }

    if (destinations[i] == 1)
    {
      printf("0");
      // out << "0";
    }
    else
    {
      printf("%d", c[destinations[i] - 1]);
      // out << c[destinations[i] - 1];
    }
  }

  printf("\n");
  // out << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T;
  size_t N,M;

  std::cin >> T;

  while (T--)
  {
    std::cin >> N >> M;
    vector cities(N);
    vector destinations(M);

    for (size_t i = 0; i < N; i++)
    {
      std::cin >> cities[i];
    }

    for (size_t i = 0; i < M; i++)
    {
      std::cin >> destinations[i];
    }

    print_minimum_time_required(cities, destinations);
  }

  // out.close();

  return 0;
}