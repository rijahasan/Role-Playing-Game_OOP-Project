#include "game.hpp"
#include "Oopdastaan.hpp"
#include "drawing.hpp"
#include "students.hpp"


SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "OOP Dastaan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets.png");
    gTexture = loadTexture("mainscreen.png");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	Oopdastaan oopmania;
	students* s9;	//main character
	s9 = new students(20, 510);
	oopmania.createDesks();
	oopmania.createStudents();

    while (!check)
    {
        SDL_RenderCopyEx(Drawing::gRenderer, gTexture, NULL, NULL, 0, 0, SDL_FLIP_NONE);
        SDL_RenderPresent(Drawing::gRenderer);
        int xMouse, yMouse;

        while (SDL_PollEvent(&e) != 0)
        {
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse << " & " << yMouse << endl;

                if (xMouse > 454 && xMouse < 548 && yMouse > 338 && yMouse < 397)		//for play buttons
                {
                    quit = false;
                    check = true;
				    gTexture = loadTexture("background.png");
                }
                // if (xMouse > 1045 && xMouse < 1165 && yMouse > 164 && yMouse < 253)		for instructions buttons
                // {
                //     quit = true;
                //     check = true;
                // }
            }
        }
    }

	// int bee_frame;
	while( !quit )
	{
		bool collided = false;
		SDL_Rect deskcollided;
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			
			if(e.type == SDL_KEYDOWN){
					if (collided == true and e.key.keysym.scancode!=SDL_SCANCODE_X)		///checks if the collision was true in the last iteration
						continue;		//implement textbox				
					else if (e.key.keysym.sym==SDLK_LEFT || e.key.keysym.sym==SDLK_RIGHT ||  e.key.keysym.sym==SDLK_DOWN || e.key.keysym.sym==SDLK_UP){
						deskcollided  = oopmania.Collision(s9, e.key.keysym.sym);
						if (deskcollided.x==0 && deskcollided.y==0 && deskcollided.w==0 && deskcollided.h==0)		//condition for no collision
							collided=false;
						else
							collided=true;
						if (collided == false)
							s9->movement(e.key.keysym.sym);
					}
			}
			
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		oopmania.drawObjects();
		s9->draw();


		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}
