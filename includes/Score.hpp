//
// Score.hpp for cpp_nibbler in /home/tran_0/rendu/cpp_nibbler/includes
// 
// Made by David Tran
// Login   <tran_0@epitech.net>
// 
// Started on  Fri Apr  3 21:11:57 2015 David Tran
// Last update Fri Apr  3 21:30:45 2015 David Tran
//

#ifndef SCORE_HPP_
# define SCORE_HPP_

class		Score
{
public:
  Score();
  ~Score();
public:
  double	getScore() const;
  double	getTime() const;
  double	getCountit() const;
  void		setScore(double const);
  void		setTime(double const);
  void		setCountit(double const);
private:
  double	score;
  double	time;
  double	countit;
};

#endif
