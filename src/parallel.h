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

#ifndef PARALLEL_H
#define PARALLEL_H

const int MAX_CPU = 32;

extern int myrank, cpusize, range[MAX_CPU][4];
extern int GATHR, SYNCH, ALL_UPDATED;

inline void set_GATHR(void) {GATHR=1; return;};
inline void clr_GATHR(void) {GATHR=0; return;};
inline int  get_GATHR(void) {return GATHR;};

inline void set_SYNCH(void) {SYNCH=1; return;};
inline void clr_SYNCH(void) {SYNCH=0; return;};
inline int  get_SYNCH(void) {return SYNCH;};

inline void set_ALL_UPDATED(void) {ALL_UPDATED=1; return;};
inline void clr_ALL_UPDATED(void) {ALL_UPDATED=0; return;};
inline int  get_ALL_UPDATED(void) {return ALL_UPDATED;};

inline void my_range(const int rank, int& iis, int& iit, int& jjs, int& jjt)
{
	iis = range[rank][0];
	iit = range[rank][2];
	jjs = range[rank][1];
	jjt = range[rank][3];
	
	return;
};

int partition(void);
int gather_array(void);
int synchronize(int i_prd);
void update_BC_node(void);
#endif
