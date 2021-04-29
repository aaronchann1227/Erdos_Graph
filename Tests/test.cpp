#include "../Graph.h"
#include "../Graph.h"



Graph makeGraph() {
  PNG png(4, 4);
  HSLAPixel blackPixel(180, 1, 0);
  
  for (unsigned i = 0; i < 4; i++) {
    png.getPixel(i, 0) = blackPixel;
    png.getPixel(0, i) = blackPixel;
    png.getPixel(i, 3) = blackPixel;
    png.getPixel(3, i) = blackPixel;
  }
  return png;
}







TEST_CASE("DFS iterator starts at the start point", "[weight=2][part=1]") {
  PNG png = getTestPNG();
  Point startPoint(1, 1);
  
  DFS dfs(png, startPoint, 0.2);
  REQUIRE( *(dfs.begin()) == startPoint );
}