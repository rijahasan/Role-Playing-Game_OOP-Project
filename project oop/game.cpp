#include "game.hpp"
#include "Oopdastaan.hpp"
#include "drawing.hpp"
#include "students.hpp"
#include <string>
#include <SDL_ttf.h>
#include "Time.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "LeniencyMeter.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::white = NULL;
SDL_Texture* Drawing::assets = NULL;
SDL_Texture* Drawing::moreassets = NULL;
SDL_Texture* Drawing::classmates = NULL;
SDL_Texture* Drawing::textboxes = NULL;



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
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                } 
				// if (TTF_Init()==-1){
				// 	printf( "TTF could not initialize!" );
				// 	}


			}
		}
	}
	// printf(TTF_Init() );
		

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	Drawing::moreassets = loadTexture("moreassets.png");
	Drawing::white = loadTexture("white.png");
	Drawing::assets = loadTexture("assets.png");
	Drawing::classmates = loadTexture("classmates.png");
	Drawing::textboxes = loadTexture("textbox.png");
	
	gTexture = loadTexture("mainscreen.png");

	if(Drawing::classmates==NULL || Drawing::moreassets==NULL || Drawing::assets==NULL || Drawing::white==NULL || gTexture==NULL || Drawing::textboxes==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic = Mix_LoadMUS("pink-panther-6836.mp3");
    RightansMusic = Mix_LoadWAV("Winner Sms.mp3");
    //WrongansMusic = Mix_LoadWAV("negative_beeps-6008.mp3");
    if (bgMusic == NULL)
    {
        printf("Unable to load music: %s \n", Mix_GetError());
        success = false;
    }
    if (RightansMusic == NULL)
    {
        printf("Unable to load crash music: %s \n", Mix_GetError());
        success = false;
    }
    /* if (WrongansMusic == NULL)
    {
        printf("Unable to load life music: %s \n", Mix_GetError());
        success = false;
    } */ 
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::white);
	SDL_DestroyTexture(Drawing::moreassets);
	SDL_DestroyTexture(Drawing::assets);
	SDL_DestroyTexture(Drawing::classmates);
	Mix_FreeChunk(RightansMusic);
	SDL_DestroyTexture(Drawing::textboxes);

	//Mix_FreeChunk(WrongansMusic);
	RightansMusic = NULL;
	//WrongansMusic = NULL;
	
	Drawing::white=NULL;
	Drawing::assets=NULL;
	Drawing::classmates=NULL;
	Drawing::textboxes=NULL;
	

	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	SDL_DestroyTexture(gTexture);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();


	delete WrongansMusic;
	delete RightansMusic;
	delete bgMusic;

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
	Time t;
	bool quit = false;
	SDL_Event e;
	Oopdastaan oopmania;
	students* s9;	//main character
	s9 = new students(20, 510);		
	oopmania.createDesks();
	oopmania.createStudents();
	bool drawinstructions=false;
	drawelements elements;
	// Text text(Drawing::gRenderer, "arialbd.ttf", 15, "HAKUNA MATATA", {255,0,0,255});
        SDL_RenderCopyEx(Drawing::gRenderer, gTexture, NULL, NULL, 0, 0, SDL_FLIP_NONE);
        SDL_RenderPresent(Drawing::gRenderer);

    while (!check)
    {
		
        int xMouse, yMouse;

        while (SDL_PollEvent(&e) != 0)
        {
			if( e.type == SDL_QUIT )
			{
				quit = true;
				check=true;
			}

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse << " & " << yMouse << endl;

                if (xMouse > 454 && xMouse < 548 && yMouse > 338 && yMouse < 397)		//for play buttons
                {
                    check = true;
				    gTexture = loadTexture("background.png");
                }
                else if (xMouse > 395 && xMouse < 610 && yMouse > 452 && yMouse < 508 && drawinstructions==false)		//for intructions buttons
					drawinstructions=true;
				else if (drawinstructions==true)
					drawinstructions=false;
            }
        }
			SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer				
			SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
			if (drawinstructions==true){
				elements.draw('I');	}
			SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
			SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds

    }
	bool completed=false;
	bool collided = false;
	SDL_Rect deskcollided;
	LeniencyMeter Lmeter;
	bool InteractOrNot=false; 
	bool continueinteract=false;
	bool correctans;
	int seconds=0;		//starting second is 0 
	int questionnumber=0;
	bool meterfull=false;
	// int bee_frame;
	while( !quit )
	{	//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 ){
			//User requests quit
			if( e.type == SDL_QUIT ){
				quit = true;
			}
			if(e.type == SDL_KEYDOWN){
					if (oopmania.getvivastatus()){
						correctans = oopmania.checkans(oopmania.getquestionnum(),e.key.keysym.sym);
						break;
					}
					if (continueinteract && e.key.keysym.sym!=SDLK_x)
						break;
					else if (continueinteract && e.key.keysym.sym==SDLK_x){
						continueinteract=false;
						break;
					}
					if (collided == true && e.key.keysym.sym==SDLK_x)	{	///checks if the collision was true in the last iteration
						InteractOrNot=oopmania.turnstudentAtDesk(deskcollided);		//implement textbox
						if (InteractOrNot){	   //if true, interact
							collided=true;		//remains collided
							continueinteract=true;
							break;
						}
						else{
							collided = false; //when the interaction is done make it false	
							cout<<"Already Interacted";
							continueinteract=false;
						}					
					}
					// and e.key.keysym.scancode==SDL_SCANCODE_X
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
		oopmania.drawObjects();
		s9->draw();

        // leniency meter: srcRect={35, 8, 130, 6}

        // leniency meter: srcRect={35, 8, 130, 6}
		if (oopmania.Isfaculty()){
			t.draw();
			Lmeter.draw();
			if (oopmania.facultyinteractionnum()==10){
				elements.draw('F');		//draws fade to highlight text
				elements.draw('Q');
				meterfull=Lmeter.IncreaseLeniency();
			}
			if (oopmania.getvivastatus()){
				seconds++;
				t.IncreaseTime(seconds);
			}
			if (correctans){
				elements.draw('C');
			}
			// else if ()
			else
				elements.draw('L');
			
		}
		if (meterfull)
			elements.draw('W');
					// system.("pause")
		if (seconds>1200){
			 elements.draw('L');
			 break;
		}
		if (InteractOrNot){
			completed=oopmania.interact(continueinteract);
			if (completed)
				continueinteract=false;		//interaction completed
			else
				continueinteract=true;
		}
		if (Mix_PlayingMusic() == 0)
        {
            Mix_PlayMusic(bgMusic, 2);
            int Mix_VolumeMusic(30);
        }
		//***********************draw the objects here********************

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}