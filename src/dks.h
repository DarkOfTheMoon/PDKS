/*
PDKS���������¼��¹�����ѧ������ʿѧλ�ڼ��о���ѹ��
LBMģ��ʱ�����ĳ���LBM��ѹ����ģ����򡣻����ص�Ϊ��
1 ֧�ֶ�ά������������
2 ֧�ֶ����ѹ��LBMģ��
3 ֧��I��������ֿ�MPI����
4 ֧��http://www.math.tu-cottbus.de/~berti/gral�е�control-device
5 �����ˡ���

�������۲�����ο��ҵ�����
��Alternative method to construct equilibrium distribution functions in 
lattice-Boltzmann method simulation of inviscid compressible flows at 
high Mach number��, Physical Review E, 2007, Vol 75 (3), 036706, Kun Qu, 
Chang Shu and Yong Tian Chew
http://serve.me.nus.edu.sg/shuchang/Publications/Latest%20papers%20for%20web/Qu_Shu_Chew%20(PRE)%202007.pdf

��ѧλ����
https://scholarbank.nus.edu.sg/handle/10635/15823



PDKS (Parallel Discrete Kinetic Solver), written by Qu Kun in 2006, is a " 
lattice Boltzmann equation solver for two dimentional compressible inviscid/viscous 
flows.
Copyright (C) <2007>  <Kun Qu>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef DKS_H
#define DKS_H

const int IDIM=61,JDIM=81;
const int ISIZE=IDIM+3, JSIZE=JDIM+3;
const int MAXDIM = IDIM>JDIM?IDIM:JDIM;

#ifdef INVISCID
  #define D2Q13L2
  const int DIR=26;
  const int NVAR=4;  //rho, u, v, e
#endif

#ifdef LAMINAR
  #define D2Q17L2
  const int DIR=34;
  const int NVAR=5;   //rho, u, v, e, tau
#endif


extern double  Q[ISIZE][JSIZE][DIR];  // current values at step n
extern double DQ[ISIZE][JSIZE][DIR];  // new values at step n+1
extern double  M[ISIZE][JSIZE][NVAR]; // rho, u, v, e;

#endif
