class Text
{
	private:
		float relativeX,
			  relativeY,
			  relativeSize;

		sf::String string;
		sf::Color color;
		sf::Font font;
		sf::Text text;

	public:
		Text(	sf::String string, sf::String fontFileName, sf::Color color,
				float relativeX, float relativeY, float relativeSize):
			relativeX(relativeX), relativeY(relativeY), relativeSize(relativeSize),
			string(string), color(color)
		{
			if (!font.loadFromFile(fontFileName)) Closed();
			text.setFont(font);
			text.setString(string);
			text.setFillColor(color);

			updatePositionAndSize();
		}

		void updatePositionAndSize()
		{
			text.setPosition(sf::Vector2f(windowSize.x * relativeX, windowSize.y * relativeY));
			text.setCharacterSize(minf(windowSize.x * relativeSize, windowSize.y * relativeSize));
		}

		void setString(sf::String newString)
		{
			string = newString;
			text.setString(string);
		}

		void setColor(sf::Color newColor)
		{
			color = newColor;
			text.setFillColor(color);
		}

		void draw()
		{ window.draw(text); }
};
