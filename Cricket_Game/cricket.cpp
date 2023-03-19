#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

//total overs
int total_overs ()
{
  ifstream read;
  read.open ("configuration.txt");
  int ovrs = 0;
  
  
  while (read >> ovrs)
    {
    	
    }
    
    read.close();
    
    cout << "Number of overs are:" << ovrs << endl;
    
  return ovrs;
}

//first innings.
void Toss (string & team_a, string & team_b, int &n, string * mema, string * memb)
{
  string bat_team1, bat_team2, ball_team1, ball_team2, toss;
  string bat_mem1[11], bat_mem2[11], ball_mem1[11], ball_mem2[11];
  
  int chos;
  srand (time (NULL));
  n = (rand () % 2) + 0;
  
  //The function for the toss between two teams 
  if (n == 1)
    {
      cout << "The team " << team_a << " won the toss" << endl;
      toss = team_a;
      //if the toss win by first team
      if (toss == team_a)
	{
	  int k = 0;
	  do
	    {
	      cout << "\n\n	" << team_a << " enter 1 for bat first & enter 2 for ball first : ";
	      cin >> chos;
	    }
	  while (chos != 1 && chos != 2);
	
	  if (chos == 1)
	    {
	      bat_team1 = team_a;
	      ball_team1 = team_b;
	      bat_team2 = team_b;
	      ball_team2 = team_a;
	      for (int i = 0; i < 11; i++)
		{
		  bat_mem1[i] = mema[i];
		  ball_mem1[i] = memb[i];
		  bat_mem2[i] = memb[i];
		  ball_mem2[i] = mema[i];
		}
	    }
	  else if (chos == 2)
	    {
	      bat_team1 = team_b;
	      ball_team1 = team_a;
	      bat_team2 = team_a;
	      ball_team2 = team_b;
	      for (int i = 0; i < 11; i++)
		{
		  bat_mem1[i] = memb[i];
		  ball_mem1[i] = mema[i];
		  bat_mem2[i] = mema[i];
		  ball_mem2[i] = memb[i];
		}
	    }
	}

    }
    //The toss decision for the next team
  else
    {
      cout << "The team " << team_b << " won the toss" << endl;
      toss = team_b;
      if (toss == team_b)
	{
	  int k = 0;
	  do
	    {
	      cout << "\n\n	" << team_b <<
		" enter 1 for bat first & enter 2 for ball first : ";
	      cin >> chos;
	    }
	  while (chos != 1 && chos != 2);
	  if (chos == 1)
	    {
	      bat_team1 = team_b;
	      ball_team1 = team_a;
	      bat_team2 = team_a;
	      ball_team2 = team_b;
	      for (int i = 0; i < 11; i++)
		{
		  bat_mem1[i] = memb[i];
		  ball_mem1[i] = mema[i];
		  bat_mem2[i] = mema[i];
		  ball_mem2[i] = memb[i];
		}
	    }
	  else if (chos == 2)
	    {
	      bat_team1 = team_a;
	      ball_team1 = team_b;
	      bat_team2 = team_b;
	      ball_team2 = team_a;
	      for (int i = 0; i < 11; i++)
		{
		  bat_mem1[i] = mema[i];
		  ball_mem1[i] = memb[i];
		  bat_mem2[i] = memb[i];
		  ball_mem2[i] = mema[i];
		}
	    }
	}

    }
  cout << "---------------------------------------------------------------" <<
    endl;

}
//function for the First innings 
void drawScoreboard_1 (int ovr, string & team_a, string & team_b, string * mema, string * memb, int &score_1)
{
  int num;
  string bowler, ball_mem1[11], batsman;
  Toss (team_a, team_b, num, mema, memb);
  //The function for the first innings of the match
  cout << "\n\n\n					1ST INNINGS" << endl
    << endl << endl;
  string toss, bat_team1, ball_team1, bat_team2, ball_team2, bat_mem1[11],
    bat_mem2[11], ball_mem2[11], runner, bat1[11], flip, result;

  int chos, happening, bat_run1[11], bat_ball1[11], bat_run2[11],
    bat_ball2[11];

  int bat_count1 = 0, score = 0, wicket = 0, batsman_run = 0, runner_run =
    0, bowler_run = 0, flip_run, flip_run1;

  int ball_count1 = 0;
  int *ball_run1 = new int[ovr];
  int *ball_wicket1 = new int[ovr];
  int *ball_bowl1 = new int[ovr];
  int ball_over = 0, ball_play = 0, wicket1 = 0, bowl_run = 0;

  string *ball1 = new string[ovr];
  srand (time (NULL));
  int hit = 0;
  int count_6 = 0, count_4 = 0;
   
  bat_team1 = team_a;
  ball_team1 = team_b;

  //loop for the number of overs in a match 
  for (int i = 0; i < ovr; i++)
    {
      //select the bowler of your choice
      cout << "\n\n	  Enter the name of bowler : ";
      cin >> bowler;
      for (int a = 0; a < 11; a++)
	{
	  if (bowler == ball_mem1[a])
	    {
	      bowler = ball_mem1[a];
	    }
	}
      for (int j = 0; j < 6; j++)
	{
	  if (i == 0 && j == 0)
	    {
//The openers of your choice
	      cout << "\n\n	Enter the Names of Openers";
	      cout << "\n	  Striker : ";
	      cin >> batsman;
	      for (int b = 0; b < 11; b++)
		{
		  if (batsman == bat_mem1[b])
		    {
		      batsman = bat_mem1[b];
		    }
		}
	      cout << "\n	  Runner : ";
	      cin >> runner;
	      for (int c = 0; c < 11; c++)
		{
		  if (runner == bat_mem1[c])
		    {
		      runner = bat_mem1[c];;
		    }
		}
	    }

	  cout << "\n\n\n	      What happened at " << i << "." << j +
	    1 << " ball : ";
	  hit = (rand () % 7) - 1;
	  cin.get ();

	  //The first five batsmans have less probability to get out
	  if (wicket >= 5)
	    {
	      hit = (rand () % 5) - 1;
	      cin.get ();
	    }
	  if (hit != -1)
	    {
	      if (hit % 2 == 0)
		{
		  score += hit;
		  batsman_run += hit;
		  bowler_run += hit;
		}
	      else
		{
		  score += hit;
		  batsman_run += hit;
		  bowler_run += hit;

		  flip = batsman;
		  batsman = runner;
		  runner = flip;

		  flip_run = batsman_run;
		  batsman_run = runner_run;
		  runner_run = flip_run;
		}
	    }
	    //When the players got out then condition for the next batsman
	  else
	    {
	      for (int x = 0; x < 11; x++)
		{
		  cout << x << "." << mema[x] << endl;
		}
	      wicket++;
	      bat1[bat_count1] = batsman;
	      bat_run1[bat_count1] = batsman_run;
	      ball_play = (i * 6) + j - ball_play;
	      bat_ball1[bat_count1] = ball_play;
	      batsman_run = 0;
	      bat_count1++;
	      cout << "\n\n	Enter Name of Next Batsman : ";
	      cin >> batsman;
	      for (int d = 0; d < 11; d++)
		{
		  if (batsman == bat_mem1[d])
		    {
		      batsman = bat_mem1[d];
		    }
		}
	    }

	  system ("clear");
	  //Live total score of the first team.
	  cout <<
	    "_________________________________________________________________________________________________________\n";
	  cout << bat_team1 << " :      " << score << "/" << wicket <<
	    "				Batsman		 Runner		  Bowler	";
	  cout << endl;
	  cout << ball_team1 << " :  	" << i << "." << j +
	    1 << "(" << ovr << ")				" << batsman
	    << "  " << batsman_run << "    	  "
	    << runner << "  " << runner_run <<
	    "    	  " << bowler << "  " << bowler_run;
	  cout << endl;
	  cout <<
	    "_________________________________________________________________________________________________________\n";
//When the players get all out
	  if (wicket == 10)
	    {
	      bat1[bat_count1] = batsman;
	      bat_run1[bat_count1] = batsman_run;
	      ball_play = (i * 6) + j - ball_play;
	      bat_ball1[bat_count1] = ball_play;
	      batsman_run = 0;
	      bat_count1++;
	      i = ovr;
	      j = 6;
	      cout << "\n\n		Innings ended (Batting Team All Out) "
		<< endl << endl << endl;
	    }

	  if (i == ovr - 1 && j == 5)
	    {
	      bat1[bat_count1] = batsman;
	      bat_run1[bat_count1] = batsman_run;
	      ball_play = (i * 6) + j - ball_play;
	      bat_ball1[bat_count1] = ball_play;
	      bat_count1++;
	      bat1[bat_count1] = runner;
	      bat_run1[bat_count1] = runner_run;
	      ball_play = (i * 6) + j - ball_play;
	      bat_ball1[bat_count1] = ball_play;
	      bat_count1++;
	    }
	}
      ball1[ball_count1] = bowler;
      ball_over = (i + 1) - ball_over;
      ball_bowl1[ball_count1] = ball_over;
      wicket1 = wicket - wicket1;
      ball_wicket1[ball_count1] = wicket1;
      ball_run1[ball_count1] = bowler_run;
      ball_count1++;

      flip = batsman;
      batsman = runner;
      runner = flip;

      flip_run = batsman_run;
      batsman_run = runner_run;
      runner_run = flip_run;

      bowler_run = 0;
    }

  cout << "\n\n\n					1ST INNINGS " << endl
    << endl << endl;
  cout << "\n\n			Batting Card" << endl << endl;
  cout << "\n\tPlayers\t\tRuns\t\tBalls\t\t6s\t\t4s";

  //loop for the batting cards
  for (int i = 0; i < bat_count1; i++)
    {
      cout << "\n\t";
      cout << bat1[i];
      cout << "\t\t";
      cout << bat_run1[i];
      cout << "\t\t";
      cout << bat_ball1[i];
      cout << endl;
      cout << "\t\t";

    }

  cout << "\n\n			Bowling Card" << endl << endl;
  cout << "\n    Players 	    Wicket 	Runs	     Overs ";

  //Loop for the bowling cards of first innings
  for (int j = 0; j < ball_count1; j++)
    {
      cout << "\n\t";
      cout << ball1[j];
      cout << "\t\t";
      cout << ball_wicket1[j];
      cout << "\t";
      cout << ball_run1[j];
      cout << "\t\t";
      cout << ball_bowl1[j];
      cout << endl;
    }
  score_1 = score;

}

//Scoreborad function.
void drawScoreboard_2 (int ovr, string & team_a, string & team_b, string * mema,string * memb, int score, int &score_2)
{


  int bat_run2[11], bat_ball2[11];

  int bat_count1 = 0, wicket = 0, batsman_run = 0, runner_run =
    0, bowler_run = 0, flip_run, flip_run1;

  int ball_count2 = 0, bat_count2 = 0;
  int *ball_run2 = new int[ovr];
  int *ball_wicket2 = new int[ovr];
  int *ball_bowl2 = new int[ovr];
  int ball_over1 = 0, ball_played = 0, wicket2 = 0, bowl_run1 = 0;

  string ball2[ovr], bowler1, batsman1, runner1, flip1, bat2[bat_count2],
    ball_mem1[11];

  string bat_team2, ball_team2, bat_mem2[11], ball_mem2[11], runner, bat1[11],
    flip, batsman, result, bat_team1;


  int target;
  target = score;
  score = 0;
  batsman_run = 0;
  bowler_run = 0;
  wicket = 0;
  runner_run = 0;
  int hit1 = 0;
  mema[11];
  memb[11];
  bat_team2 = team_b;
  ball_team2 = team_a;

  cout << "\n\n\n					2ND INNINGS " << endl
    << endl << endl;

  for (int i = 0; i < ovr; i++)
    {
      cout << "\n\n	  Enter the name of bowler : ";
      cin >> bowler1;
      for (int a = 0; a < 11; a++)
	{
	  if (bowler1 == ball_mem2[a])
	    {
	      bowler1 = ball_mem2[a];
	    }
	}
      for (int j = 0; j < 6; j++)
	{
	  if (i == 0 && j == 0)
	    {

	      cout << "\n\n	Enter the Names of Openers";
	      cout << "\n	  Striker : ";
	      cin >> batsman1;
	      for (int b = 0; b < 11; b++)
		{
		  if (batsman1 == bat_mem2[b])
		    {
		      batsman1 = bat_mem2[b];
		    }
		}
	      cout << "\n	  Runner : ";
	      cin >> runner1;
	      for (int c = 0; c < 11; c++)
		{
		  if (runner1 == bat_mem2[c])
		    {
		      runner1 = bat_mem2[c];;
		    }
		}
	    }
	  cout << "\n\n\n	  What happened at " << i << "." << j +
	    1 << " ball : ";
	  hit1 = (rand () % 7) - 1;
	  cin.get ();

	  //The first five batsmans have less probability to get out
	  if (wicket >= 5)
	    {
	      hit1 = (rand () % 5) - 1;
	      cin.get ();
	    }
	    
	  //After acheiving target.  
	  if(score > target)
	  {
	  		cout << team_b << " won the match." << endl;
	  		break;
	  }

	  if (hit1 != -1)
	    {
	      if (hit1 % 2 == 0)
		{
		  score += hit1;
		  batsman_run += hit1;
		  bowler_run += hit1;
		}
	      else
		{
		  score += hit1;
		  batsman_run += hit1;
		  bowler_run += hit1;

		  flip = batsman;
		  batsman = runner;
		  runner = flip;

		  flip_run = batsman_run;
		  batsman_run = runner_run;
		  runner_run = flip_run;
		}
	    }
	     //When the players got out then condition for the next batsman
	  else
	    {
	      for (int x = 0; x < 11; x++)
		{
		  cout << x << "." << memb[x] << endl;
		}
	      wicket++;
	      bat2[bat_count2] = batsman1;
	      bat_run2[bat_count2] = batsman_run;
	      ball_played = (i * 6) + j - ball_played;
	      bat_ball2[bat_count2] = ball_played;
	      batsman_run = 0;
	      bat_count1++;
	      cout << "\n\n	Enter Name of Next Batsman : ";
	      cin >> batsman1;
	      for (int d = 0; d < 11; d++)
		{
		  if (batsman1 == bat_mem2[d])
		    {
		      batsman1 = bat_mem2[d];
		    }
		}
	    }

	  system ("clear");
	  //live score for the second team
	  cout <<
	    "_________________________________________________________________________________________________________\n";
	  cout << bat_team2 << " :      " << score << "/" << wicket <<
	    "				Batsman		 Runner		  Bowler	";
	  cout << endl;
	  cout << ball_team2 << " :  	" << i << "." << j +
	    1 << "(" << ovr << ")				" << batsman1
	    << "  " << batsman_run << "    	  "
	    << runner1 << "  " << runner_run <<
	    "    	  " << bowler1 << "  " << bowler_run;
	  cout << endl;
	  cout <<
	    "_________________________________________________________________________________________________________\n";


	  if (wicket == 10 && score < target)
	    {
	      bat2[bat_count2] = batsman1;
	      bat_run2[bat_count2] = batsman_run;
	      ball_played = (i * 6) + j - ball_played;
	      bat_ball2[bat_count2] = ball_played;
	      batsman_run = 0;
	      bat_count2++;
	      i = ovr;
	      j = 6;
	      cout << "\n\n		Innings ended (Batting Team All Out) "
		<< endl << endl << endl;
	      result = bat_team1;
	    }


	  if (i == ovr - 1 && j == 5)
	    {
	      bat2[bat_count2] = batsman1;
	      bat_run2[bat_count2] = batsman_run;
	      ball_played = (i * 6) + j - ball_played;
	      bat_ball2[bat_count2] = ball_played;
	      bat_count2++;
	      bat2[bat_count2] = runner;
	      bat_run2[bat_count2] = runner_run;
	      ball_played = (i * 6) + j - ball_played;
	      bat_ball2[bat_count2] = ball_played;
	      bat_count1++;
	    }
	}


      ball2[ball_count2] = bowler1;
      ball_over1 = (i + 1) - ball_over1;
      ball_bowl2[ball_count2] = ball_over1;
      wicket2 = wicket - wicket2;
      ball_wicket2[ball_count2] = wicket2;
      ball_run2[ball_count2] = bowler_run;
      ball_count2++;

      flip1 = batsman1;
      batsman1 = runner1;
      runner1 = flip1;

      flip_run = batsman_run;
      batsman_run = runner_run;
      runner_run = flip_run;

      bowler_run = 0;
    }

  cout << "\n\n\n					2ND INNINGS " << endl
    << endl << endl;
    //BAtting card for run chasing team
  cout << "\n\n			Batting Card" << endl << endl;
  cout << "\n\t Players 	  Runs  	  Balls ";

  for (int i = 0; i < bat_count2; i++)
    {
      cout << "\n\t";
      cout << bat2[i];
      cout << "\t\t";
      cout << bat_run2[i];
      cout << "\t\t";
      cout << bat_ball2[i];
      cout << endl;
    }
    //Bowling card for runs chasing team
  cout << "\n\n			Bowling Card" << endl << endl;
  cout << "\n\t Players 	 Wicket 	Runs	Overs ";
  for (int j = 0; j < ball_count2; j++)
    {
      cout << "\n\t";
      cout << ball2[j];
      cout << "\t\t";
      cout << ball_wicket2[j];
      cout << "\t";
      cout << ball_run2[j];
      cout << "\t";
      cout << ball_bowl2[j];
      cout << endl;
    }
  score_2 = score;

}


//summary function
void summary (int s1, int s2, string & team_a, string & team_b)
{

  cout << "\n\n\t\t\tThe target was: " << s1 << endl;

  if (s1 > s2)
    {
      cout << "\n\n\n\n					" << team_a << " won the match";
    }
  else
    {
      cout << "\n\n\n\n					" << team_b << " won the match!";
    }

}



int main ()
{
  string team_a = "Pakistan", team_b = "England", result;

  string mema[11] = { "Babar", "Rizwan", "Faqar", "Haider", "Sharjeel", "Shadab", "Malik", "Zakir", "Hassan", "Rauf", "Shaheen"};
  string memb[11] = { "Morgan", "Root", "Buttler", "Bairstow", "Roy", "Woakes", "Stokes","Wood", "Rrcher", "Moeen", "Curran"};

  int ovr = total_overs ();
  int score_1, score_2;
 // cout << total_overs () << endl;

  int num;

  //Calling the functions to draw the score board.	
  drawScoreboard_1 (ovr, team_a, team_b, mema, memb, score_1);
  drawScoreboard_2 (ovr, team_a, team_b, mema, memb, score_1, score_2);
  summary (score_1, score_2, team_a, team_b);

  return 0;
}

