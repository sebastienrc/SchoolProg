float GetDistanceBetween(Point2f fromPoint, Point2f toPoint)
{
    return sqrtf(powf(toPoint.x - fromPoint.x, 2) + powf(toPoint.y - fromPoint.y, 2));
}

float GetAngleDifference(float fromAngle, float toAngle)
{
    return atan2f(sinf(toAngle - fromAngle), cosf(toAngle - fromAngle));
}

float GetAngleToPoint(Point2f fromPoint, Point2f toPoint)
{
    return atan2(toPoint.y - fromPoint.y, toPoint.x - fromPoint.x);
}

float RadiansToDegrees(float radians)
{
    return radians / g_Pi * 180;
}

float DegreesToRadians(float degrees)
{
    return degrees / 180 * g_Pi;
}

int GetNumberFromUser(std::string inputText, std::string invalidText, int min = INT_MIN, int max = INT_MAX)
{
    int number{};

    while (true)
    {
        std::cout << inputText;
        std::cin >> number;

        if (std::cin.fail() || std::cin.peek() != '\n' || number < min || number > max)
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << invalidText << std::endl;

            continue;
        }

        return number;
    }

    return 0;
}

float RandomRange(float min, float max)
{
    // Inverse in case of the opposite
    if (min > max)
    {
        const float tempMax = max;
        max = min;
        min = tempMax;
    }

    const float randomAlpha{ float(rand()) / RAND_MAX };
    const float range{ max - min };

    return randomAlpha * range + min;
}

int   RandomRange(int min, int max)
{
    // Inverse in case of the opposite
    if (min > max)
    {
        const int tempMax = max;
        max = min;
        min = tempMax;
    }

    return rand() % (max - min + 1) + min;
}