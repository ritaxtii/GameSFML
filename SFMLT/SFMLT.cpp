/*#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <locale>
using namespace std;

int main()
{
    sf::RenderWindow window({ 640 ,480 }, "test");
    
    sf::Music music;
    music.openFromFile("song1.wav");
     music.play();
     sf::Clock cl;
     long long time;
     while (window.isOpen())
     {
         time = cl.getElapsedTime().asMilliseconds();
         sf::Event event;

         
             while (window.pollEvent(event))
             {                                                                     
                 switch (event.type)
                 {
                 case sf::Event::KeyReleased:
                     switch (event.key.code)
                     {
                     case sf::Keyboard::Space:
                         cout << time << endl;
                         break;
                
                     }


                 }
                 if (event.type == sf::Event::Closed)
                     window.close();
             }


             window.clear();
             window.display();
         
     }


   
}*/
#define _CRT_SECURE_NO_DEPRECATE
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <locale>
using namespace std;

int main()
{
    sf::RenderWindow window({ 1152 ,720 }, "test");

    sf::Texture texture;
    texture.loadFromFile("Pic/bg.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(0, 0);

    sf::Texture texture2;
    texture2.loadFromFile("Pic/center.png");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setPosition(sf::Vector2f(523, 307));

    /*sf::Texture texture3;
    texture3.loadFromFile("Pic/xx.png");
    sf::Sprite sprite3;
    sprite3.setTexture(texture3);
    sprite3.setPosition(sf::Vector2f(-106, 307));*/

    /*sf::Texture texture4;
    texture4.loadFromFile("Pic/aa.png");
    sf::Sprite sprite4;
    sprite4.setTexture(texture4);
    sprite4.setPosition(sf::Vector2f(1152, 307));*/
   
    sf::Sprite myArray[1000];
    sf::Texture tex[1000];
    FILE* fp;
    char time1[100];
    vector<pair<int,sf::Sprite>> vec;
    fp = fopen("song1.txt", "r");
    int n = 0;
    while (!feof(fp))
    {
       
        int  num = 0;
        fgets(time1, 100, fp);

        for (int i = 0; i < strlen(time1) - 1; i++)
        {
            num = (num * 10) + time1[i] - 48;
        }
       
        
        if (n % 2 == 0)
        {   
            tex[n].loadFromFile("Pic/xx.png");
            myArray[n].setTexture(tex[n]);
            myArray[n].setPosition(sf::Vector2f(-106, 307));
        }
        if (n % 2 == 1)
        {
            sf::Texture texture3;
            tex[n].loadFromFile("Pic/aa.png");
            myArray[n].setTexture(tex[n]);
            myArray[n].setPosition(sf::Vector2f(1152, 307));
        }

        
        vec.push_back(make_pair(num, myArray[n]));
        
        n++;

    }
    fclose(fp);
    if (!vec.empty())
        vec.erase(vec.end() - 1);

   /* for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }*/



    sf::Music music;
    music.openFromFile("song1.wav");
    music.play();
    sf::Clock cl;
    cl.restart();
    long long time;
    while (window.isOpen())
    {
        
        time = cl.getElapsedTime().asMilliseconds();
        sf::Event event;

        
        
        

        
        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].first >= time -3000 && vec[i].first <= time)
            {
                if(i%2==0 && vec[i].second.getPosition().x <= 523)
                window.draw(vec[i].second), vec[i].second.move(0.3f, 0.0f);
                else if (i % 2 == 1 && vec[i].second.getPosition().x >= 523)
                    window.draw(vec[i].second), vec[i].second.move(-0.3f, 0.0f);
            }
        }
        /*if (sprite4.getPosition().x >= 523)
            window.draw(sprite4), sprite4.move(-0.3f, 0.0f);
        else cout << time << endl; //2750
        if (sprite3.getPosition().x <= 523)
            window.draw(sprite3), sprite3.move(0.3f, 0.0f);
        else window.close(); //2750*/
       
            
        
        
        
        window.display();

    }



}