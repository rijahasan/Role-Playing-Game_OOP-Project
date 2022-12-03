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

using namespace std;

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
	bool correctans=false;
	int questionnumber=0;
	bool newans=true;
	bool nextques=false;		//checks whether to move on to next question
	bool queanswered=false;			//checks if a question is answered
	// int bee_frame;
	while( !quit )
	{	//Handle events on queue

		while( SDL_PollEvent( &e ) != 0 ){
			//User requests quit
			if(e.type == SDL_QUIT){
				quit = true;
				break;
			}
			if (win || lost || t.timerout())
				break;
			if(e.type == SDL_KEYDOWN){
					if (oopmania.Isfaculty() && oopmania.facultyinteractionnum()==9){		//case where viva is just about to start
						if (e.key.keysym.sym==SDLK_x){
							continueinteract=false;
							InteractOrNot=true;
							break;
						}
						else{
							break;
						}
					}
					if (oopmania.getvivastatus() && !queanswered && (e.key.keysym.sym==SDLK_y || e.key.keysym.sym==SDLK_n)){		//case where a question is answered
						correctans = oopmania.checkans(oopmania.getquestionnum(),e.key.keysym.sym);		//calling check ans function
						InteractOrNot=true;		//wont move on until x is pressed 
						queanswered=true;
						newans=true;
						continueinteract =  true;
						break;
					}
					else if (oopmania.getvivastatus() && e.key.keysym.sym==SDLK_x && queanswered){		//if last question was answeresd and x is pressed 
						newans=false;		//onlu move to nect ques when x is pressed and que answered
						continueinteract=false;
						nextques=true;
						queanswered=false;
						InteractOrNot=true;
						// InteractOrNot=oopmania.interactedstatus(0);
						break;
					}
					else if (oopmania.getvivastatus() && queanswered){
						InteractOrNot=true;
						newans=false;
						continueinteract=true;
						break;
					}
					else if (oopmania.getvivastatus()){
						// InteractOrNot=true;
						// newans=false;
						// nextques=false;
						// continueinteract=true;
						continue;
					}	
					if (continueinteract && e.key.keysym.sym!=SDLK_x && collided)		//if x is not pressed, game won't move on to the nect statement in the interaction
						break;
					else if (continueinteract && e.key.keysym.sym==SDLK_x && collided){ 		//if x is pressed, game moves on to the nect statement in the interaction
						continueinteract=false;
						break;
					}
					if (collided && e.key.keysym.sym==SDLK_x)	{	///checks if the collision was true in the last iteration and that x is pressed
						InteractOrNot=oopmania.turnstudentAtDesk(deskcollided);	//turns the student at desk of collision
						if (InteractOrNot){	   //if the interaction has not happened, interact
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
						deskcollided  = oopmania.Collision(s9, e.key.keysym.sym);		//if arrow keys are pressed, it checks for collision with desks and returns its position is terms of its moverrect  
						if (deskcollided.x==0 && deskcollided.y==0 && deskcollided.w==0 && deskcollided.h==0)		//condition for no collision
							collided=false;
						else
							collided=true;
						if (collided == false){
							s9->movement(e.key.keysym.sym);
						}
					}
			}
		}
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer				
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		oopmania.drawObjects();
		s9->draw();
		if (win)
			elements.draw('W');
		else if(lost)
			elements.draw('L');
		else if (t.timerout())
			elements.draw('T');
		if (oopmania.Isfaculty()){
				cout<<oopmania.facultyinteractionnum();
				if (oopmania.facultyinteractionnum()==9){
					if (InteractOrNot==false){
						elements.draw('F');		//draws fade to highlight text
						elements.draw('Q');}
					else
						elements.draw('F');	
					// if (InteractOrNot){
					// 	oopmania.interact(false);		//going to next intercation
					// 	InteractOrNot=false;
					// 	continue;
					// }
				}
				if (oopmania.getvivastatus() && !win && !lost && !(t.timerout())){
					elements.draw('F');
					elements.draw('Y');
					t.draw();
					t.seconds++;
					++t;		//operator overloading
					if (queanswered && correctans){
						elements.draw('C');
						if (newans){
							++Lmeter;
							Lmeter.draw();
							newans=false;
						}
						InteractOrNot=false;
					}
					else if (queanswered && !correctans){
						elements.draw('L');		//if any answer is wrong game is lost
						lost=true;
						InteractOrNot=false;
					}
					Lmeter.draw();
					// else if ()
					
				if (Lmeter.full && !lost){
					elements.draw('W');
					win=true;
							// system.("pause")
				}
				if (t.timerout() and !win){
					elements.draw('T');
					lost =true ;
				}
			}
		}
		if (InteractOrNot && !win && !lost && !(t.timerout())){
			if (!oopmania.getvivastatus())
				completed=oopmania.interact(continueinteract);
			else{
				completed=oopmania.interact(!nextques);
				// queanswered=false;
				// nextques=false;
			}
			if (oopmania.getvivastatus()){
					if (nextques){
						InteractOrNot=true;
						queanswered=false;
						nextques=false;
						newans=false;
						}
					else{
						InteractOrNot=true;
						newans=false;
					}
	
				// 	else{
				// 		InteractOrNot=true;
				// 		queanswered=false;
				// }
				elements.draw('Y');
			}
			else if (oopmania.facultyinteractionnum()==9){
				elements.draw('Q');
			}
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
		// if (win || lost)
		// 	SDL_Delay(1000);
        // leniency meter: srcRect={35, 8, 130, 6}
        // leniency meter: srcRect={35, 8, 130, 6}
