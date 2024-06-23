/*
 * Brief
 *   This class is for pong game.
 */

/*
 * Brief  This class is for paddle
 *****************************************************************************/
class Paddle {
  Point position = new Point();
  Size size;

  Paddle(Size paddleSize, int xPosition)
  {
    size = paddleSize;
    position.x = xPosition;
    position.y = height / 2;
  }

  void moveTo(int yPosition)
  {
    position.y = yPosition;
  }

  void display()
  {
    rectMode(CENTER);
    noStroke();
    fill(255, 255, 255);
    rect(position.x, position.y, size.width, size.height);
  }
}
