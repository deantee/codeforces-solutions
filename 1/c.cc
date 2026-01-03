#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<pair<double, double>> points;
  points.reserve(4);
  for (ll i{}; i < 3; ++i) {
    double x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }
  points.push_back(points[0]);
  auto dist = [](const pair<double, double>& p1,
                 const pair<double, double>& p2) -> double {
    double dx{p1.first - p2.first};
    double dy{p1.second - p2.second};
    return sqrt(dx * dx + dy * dy);
  };
  vector<double> dists;
  dists.reserve(5);
  for (ll i{}; i < 3; ++i) {
    dists.emplace_back(dist(points[i], points[i + 1]));
  }
  dists.push_back(dists[0]);
  dists.push_back(dists[1]);
  vector<double> angles(3);
  auto angle = [&](double a, double b, double c) -> double {
    return acos(max(-1.0, min(1.0, (b * b + c * c - a * a) / (2 * b * c))));
  };
  for (ll i{}; i < 3; ++i) {
    angles[i] = angle(dists[i], dists[i + 1], dists[i + 2]) * 2;
  }
  for (ll i{3}; i <= 100; ++i) {
    double base{acos(-1.0) * 2.0 / i};
    bool bl{true};
    for (ll j{}; j < 3; ++j) {
      double t{angles[j] / base};
      if (fabs(t - round(t)) > 1e-3) {
        bl = false;
        break;
      }
    }
    double r{dists[2] / sin(angles[2] / 2.0) / 2.0};
    if (bl) {
      cout << fixed << setprecision(6) << i * r * r * sin(base) / 2.0 << '\n';
      return 0;
    }
  }
}
