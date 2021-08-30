/// autogenerated analytical inverse kinematics code from ikfast program part of OpenRAVE
/// \author Rosen Diankov
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///     http://www.apache.org/licenses/LICENSE-2.0
/// 
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// ikfast version 0x1000004a generated on 2020-08-13 14:32:48.703093
/// Generated using solver translationxy2d
/// To compile with gcc:
///     gcc -lstdc++ ik.cpp
/// To compile without any main function as a shared object (might need -llapack):
///     gcc -fPIC -lstdc++ -DIKFAST_NO_MAIN -DIKFAST_CLIBRARY -shared -Wl,-soname,libik.so -o libik.so ik.cpp
#define IKFAST_HAS_LIBRARY
#include "ikfast.h" // found inside share/openrave-X.Y/python/ikfast.h
using namespace ikfast;

// check if the included ikfast version matches what this file was compiled with
#define IKFAST_COMPILE_ASSERT(x) extern int __dummy[(int)x]
IKFAST_COMPILE_ASSERT(IKFAST_VERSION==0x1000004a);

#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#include <complex>

#ifndef IKFAST_ASSERT
#include <stdexcept>
#include <sstream>
#include <iostream>

#ifdef _MSC_VER
#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCDNAME__
#endif
#endif

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __func__
#endif

#define IKFAST_ASSERT(b) { if( !(b) ) { std::stringstream ss; ss << "ikfast exception: " << __FILE__ << ":" << __LINE__ << ": " <<__PRETTY_FUNCTION__ << ": Assertion '" << #b << "' failed"; throw std::runtime_error(ss.str()); } }

#endif

#if defined(_MSC_VER)
#define IKFAST_ALIGNED16(x) __declspec(align(16)) x
#else
#define IKFAST_ALIGNED16(x) x __attribute((aligned(16)))
#endif

#define IK2PI  ((IkReal)6.28318530717959)
#define IKPI  ((IkReal)3.14159265358979)
#define IKPI_2  ((IkReal)1.57079632679490)

#ifdef _MSC_VER
#ifndef isnan
#define isnan _isnan
#endif
#ifndef isinf
#define isinf _isinf
#endif
//#ifndef isfinite
//#define isfinite _isfinite
//#endif
#endif // _MSC_VER

// lapack routines
extern "C" {
  void dgetrf_ (const int* m, const int* n, double* a, const int* lda, int* ipiv, int* info);
  void zgetrf_ (const int* m, const int* n, std::complex<double>* a, const int* lda, int* ipiv, int* info);
  void dgetri_(const int* n, const double* a, const int* lda, int* ipiv, double* work, const int* lwork, int* info);
  void dgesv_ (const int* n, const int* nrhs, double* a, const int* lda, int* ipiv, double* b, const int* ldb, int* info);
  void dgetrs_(const char *trans, const int *n, const int *nrhs, double *a, const int *lda, int *ipiv, double *b, const int *ldb, int *info);
  void dgeev_(const char *jobvl, const char *jobvr, const int *n, double *a, const int *lda, double *wr, double *wi,double *vl, const int *ldvl, double *vr, const int *ldvr, double *work, const int *lwork, int *info);
}

using namespace std; // necessary to get std math routines

#ifdef IKFAST_NAMESPACE
namespace IKFAST_NAMESPACE {
#endif

inline float IKabs(float f) { return fabsf(f); }
inline double IKabs(double f) { return fabs(f); }

inline float IKsqr(float f) { return f*f; }
inline double IKsqr(double f) { return f*f; }

inline float IKlog(float f) { return logf(f); }
inline double IKlog(double f) { return log(f); }

// allows asin and acos to exceed 1. has to be smaller than thresholds used for branch conds and evaluation
#ifndef IKFAST_SINCOS_THRESH
#define IKFAST_SINCOS_THRESH ((IkReal)1e-7)
#endif

// used to check input to atan2 for degenerate cases. has to be smaller than thresholds used for branch conds and evaluation
#ifndef IKFAST_ATAN2_MAGTHRESH
#define IKFAST_ATAN2_MAGTHRESH ((IkReal)1e-7)
#endif

// minimum distance of separate solutions
#ifndef IKFAST_SOLUTION_THRESH
#define IKFAST_SOLUTION_THRESH ((IkReal)1e-6)
#endif

// there are checkpoints in ikfast that are evaluated to make sure they are 0. This threshold speicfies by how much they can deviate
#ifndef IKFAST_EVALCOND_THRESH
#define IKFAST_EVALCOND_THRESH ((IkReal)0.00001)
#endif


inline float IKasin(float f)
{
IKFAST_ASSERT( f > -1-IKFAST_SINCOS_THRESH && f < 1+IKFAST_SINCOS_THRESH ); // any more error implies something is wrong with the solver
if( f <= -1 ) return float(-IKPI_2);
else if( f >= 1 ) return float(IKPI_2);
return asinf(f);
}
inline double IKasin(double f)
{
IKFAST_ASSERT( f > -1-IKFAST_SINCOS_THRESH && f < 1+IKFAST_SINCOS_THRESH ); // any more error implies something is wrong with the solver
if( f <= -1 ) return -IKPI_2;
else if( f >= 1 ) return IKPI_2;
return asin(f);
}

// return positive value in [0,y)
inline float IKfmod(float x, float y)
{
    while(x < 0) {
        x += y;
    }
    return fmodf(x,y);
}

// return positive value in [0,y)
inline double IKfmod(double x, double y)
{
    while(x < 0) {
        x += y;
    }
    return fmod(x,y);
}

inline float IKacos(float f)
{
IKFAST_ASSERT( f > -1-IKFAST_SINCOS_THRESH && f < 1+IKFAST_SINCOS_THRESH ); // any more error implies something is wrong with the solver
if( f <= -1 ) return float(IKPI);
else if( f >= 1 ) return float(0);
return acosf(f);
}
inline double IKacos(double f)
{
IKFAST_ASSERT( f > -1-IKFAST_SINCOS_THRESH && f < 1+IKFAST_SINCOS_THRESH ); // any more error implies something is wrong with the solver
if( f <= -1 ) return IKPI;
else if( f >= 1 ) return 0;
return acos(f);
}
inline float IKsin(float f) { return sinf(f); }
inline double IKsin(double f) { return sin(f); }
inline float IKcos(float f) { return cosf(f); }
inline double IKcos(double f) { return cos(f); }
inline float IKtan(float f) { return tanf(f); }
inline double IKtan(double f) { return tan(f); }
inline float IKsqrt(float f) { if( f <= 0.0f ) return 0.0f; return sqrtf(f); }
inline double IKsqrt(double f) { if( f <= 0.0 ) return 0.0; return sqrt(f); }
inline float IKatan2Simple(float fy, float fx) {
    return atan2f(fy,fx);
}
inline float IKatan2(float fy, float fx) {
    if( isnan(fy) ) {
        IKFAST_ASSERT(!isnan(fx)); // if both are nan, probably wrong value will be returned
        return float(IKPI_2);
    }
    else if( isnan(fx) ) {
        return 0;
    }
    return atan2f(fy,fx);
}
inline double IKatan2Simple(double fy, double fx) {
    return atan2(fy,fx);
}
inline double IKatan2(double fy, double fx) {
    if( isnan(fy) ) {
        IKFAST_ASSERT(!isnan(fx)); // if both are nan, probably wrong value will be returned
        return IKPI_2;
    }
    else if( isnan(fx) ) {
        return 0;
    }
    return atan2(fy,fx);
}

template <typename T>
struct CheckValue
{
    T value;
    bool valid;
};

template <typename T>
inline CheckValue<T> IKatan2WithCheck(T fy, T fx, T epsilon)
{
    CheckValue<T> ret;
    ret.valid = false;
    ret.value = 0;
    if( !isnan(fy) && !isnan(fx) ) {
        if( IKabs(fy) >= IKFAST_ATAN2_MAGTHRESH || IKabs(fx) > IKFAST_ATAN2_MAGTHRESH ) {
            ret.value = IKatan2Simple(fy,fx);
            ret.valid = true;
        }
    }
    return ret;
}

inline float IKsign(float f) {
    if( f > 0 ) {
        return float(1);
    }
    else if( f < 0 ) {
        return float(-1);
    }
    return 0;
}

inline double IKsign(double f) {
    if( f > 0 ) {
        return 1.0;
    }
    else if( f < 0 ) {
        return -1.0;
    }
    return 0;
}

template <typename T>
inline CheckValue<T> IKPowWithIntegerCheck(T f, int n)
{
    CheckValue<T> ret;
    ret.valid = true;
    if( n == 0 ) {
        ret.value = 1.0;
        return ret;
    }
    else if( n == 1 )
    {
        ret.value = f;
        return ret;
    }
    else if( n < 0 )
    {
        if( f == 0 )
        {
            ret.valid = false;
            ret.value = (T)1.0e30;
            return ret;
        }
        if( n == -1 ) {
            ret.value = T(1.0)/f;
            return ret;
        }
    }

    int num = n > 0 ? n : -n;
    if( num == 2 ) {
        ret.value = f*f;
    }
    else if( num == 3 ) {
        ret.value = f*f*f;
    }
    else {
        ret.value = 1.0;
        while(num>0) {
            if( num & 1 ) {
                ret.value *= f;
            }
            num >>= 1;
            f *= f;
        }
    }
    
    if( n < 0 ) {
        ret.value = T(1.0)/ret.value;
    }
    return ret;
}

/// solves the forward kinematics equations.
/// \param pfree is an array specifying the free joints of the chain.
IKFAST_API void ComputeFk(const IkReal* j, IkReal* eetrans, IkReal* eerot) {
IkReal x0;
x0=IKcos(j[1]);
eetrans[0]=((0.14350148)+(((-0.48)*(IKsin(j[1]))*(IKsin(j[2]))))+(((0.48)*x0*(IKcos(j[2]))))+(((0.33)*x0)));
eetrans[1]=-0.65890959;
}

IKFAST_API int GetNumFreeParameters() { return 1; }
IKFAST_API int* GetFreeParameters() { static int freeparams[] = {1}; return freeparams; }
IKFAST_API int GetNumJoints() { return 3; }

IKFAST_API int GetIkRealSize() { return sizeof(IkReal); }

IKFAST_API int GetIkType() { return 0x22000008; }

class IKSolver {
public:
IkReal j0,cj0,sj0,htj0,j0mul,j2,cj2,sj2,htj2,j2mul,j1,cj1,sj1,htj1,new_px,px,npx,new_py,py,npy,pz;
unsigned char _ij0[2], _nj0,_ij2[2], _nj2,_ij1[2], _nj1;

IkReal j100, cj100, sj100;
unsigned char _ij100[2], _nj100;
bool ComputeIk(const IkReal* eetrans, const IkReal* eerot, const IkReal* pfree, IkSolutionListBase<IkReal>& solutions) {
j0=numeric_limits<IkReal>::quiet_NaN(); _ij0[0] = -1; _ij0[1] = -1; _nj0 = -1; j2=numeric_limits<IkReal>::quiet_NaN(); _ij2[0] = -1; _ij2[1] = -1; _nj2 = -1;  _ij1[0] = -1; _ij1[1] = -1; _nj1 = 0; 
for(int dummyiter = 0; dummyiter < 1; ++dummyiter) {
    solutions.Clear();
j1=pfree[0]; cj1=cos(pfree[0]); sj1=sin(pfree[0]);
px = eetrans[0]; py = eetrans[1];

new_px=((-0.14350148)+px);
new_py=0.965601888161662;
px = new_px; py = new_py;
{
IkReal verifyeval[1];
verifyeval[0]=((1.0)+(((-10.9685203466052)*py)));
if( IKabs(verifyeval[0]) < 0.0000010000000000  )
{
{
IkReal j0array[2], cj0array[2], sj0array[2];
bool j0valid[2]={false};
_nj0 = 2;
IkReal x1=((0.33)*sj1);
if((((0.9216)+(((-0.4356)*(cj1*cj1)))+(((2.64)*cj1*px))+(((-4.0)*(px*px))))) < -0.00001)
continue;
IkReal x2=((0.5)*(IKsqrt(((0.9216)+(((-0.4356)*(cj1*cj1)))+(((2.64)*cj1*px))+(((-4.0)*(px*px)))))));
j0array[0]=(pz+(((-1.0)*x1))+(((-1.0)*x2)));
sj0array[0]=IKsin(j0array[0]);
cj0array[0]=IKcos(j0array[0]);
j0array[1]=(x2+pz+(((-1.0)*x1)));
sj0array[1]=IKsin(j0array[1]);
cj0array[1]=IKcos(j0array[1]);
j0valid[0] = true;
j0valid[1] = true;
for(int ij0 = 0; ij0 < 2; ++ij0)
{
if( !j0valid[ij0] )
{
    continue;
}
_ij0[0] = ij0; _ij0[1] = -1;
for(int iij0 = ij0+1; iij0 < 2; ++iij0)
{
if( j0valid[iij0] && IKabs(cj0array[ij0]-cj0array[iij0]) < IKFAST_SOLUTION_THRESH && IKabs(sj0array[ij0]-sj0array[iij0]) < IKFAST_SOLUTION_THRESH )
{
    j0valid[iij0]=false; _ij0[1] = iij0; break; 
}
}
j0 = j0array[ij0]; cj0 = cj0array[ij0]; sj0 = sj0array[ij0];

{
IkReal j2array[1], cj2array[1], sj2array[1];
bool j2valid[1]={false};
_nj2 = 1;
IkReal x3=((2.08333333333333)*cj1);
IkReal x4=((2.08333333333333)*sj1);
if( IKabs(((((-1.0)*px*x4))+(((-1.0)*j0*x3))+((pz*x3)))) < IKFAST_ATAN2_MAGTHRESH && IKabs(((-0.6875)+(((-1.0)*j0*x4))+((px*x3))+((pz*x4)))) < IKFAST_ATAN2_MAGTHRESH && IKabs(IKsqr(((((-1.0)*px*x4))+(((-1.0)*j0*x3))+((pz*x3))))+IKsqr(((-0.6875)+(((-1.0)*j0*x4))+((px*x3))+((pz*x4))))-1) <= IKFAST_SINCOS_THRESH )
    continue;
j2array[0]=IKatan2(((((-1.0)*px*x4))+(((-1.0)*j0*x3))+((pz*x3))), ((-0.6875)+(((-1.0)*j0*x4))+((px*x3))+((pz*x4))));
sj2array[0]=IKsin(j2array[0]);
cj2array[0]=IKcos(j2array[0]);
if( j2array[0] > IKPI )
{
    j2array[0]-=IK2PI;
}
else if( j2array[0] < -IKPI )
{    j2array[0]+=IK2PI;
}
j2valid[0] = true;
for(int ij2 = 0; ij2 < 1; ++ij2)
{
if( !j2valid[ij2] )
{
    continue;
}
_ij2[0] = ij2; _ij2[1] = -1;
for(int iij2 = ij2+1; iij2 < 1; ++iij2)
{
if( j2valid[iij2] && IKabs(cj2array[ij2]-cj2array[iij2]) < IKFAST_SOLUTION_THRESH && IKabs(sj2array[ij2]-sj2array[iij2]) < IKFAST_SOLUTION_THRESH )
{
    j2valid[iij2]=false; _ij2[1] = iij2; break; 
}
}
j2 = j2array[ij2]; cj2 = cj2array[ij2]; sj2 = sj2array[ij2];
{
IkReal evalcond[4];
IkReal x5=IKcos(j2);
IkReal x6=IKsin(j2);
IkReal x7=cj1*cj1;
IkReal x8=x5*x5;
IkReal x9=(sj1*x6);
IkReal x10=(cj1*x5);
evalcond[0]=((((-1.0)*cj1*pz))+((cj1*j0))+((px*sj1))+(((0.48)*x6)));
evalcond[1]=((-0.33)+(((-0.48)*x5))+((cj1*px))+(((-1.0)*j0*sj1))+((pz*sj1)));
evalcond[2]=((((0.48)*x10))+(((-0.48)*x9))+(((-1.0)*px))+(((0.33)*cj1)));
evalcond[3]=((0.2387119689)+(((-1.0)*(px*px)))+(((-0.2304)*x8))+(((0.4608)*x7*x8))+(((-0.3168)*cj1*x9))+(((0.3168)*x5*x7))+(((-0.4608)*x10*x9))+(((-0.1215)*x7))+(((-1.0)*(py*py))));
if( IKabs(evalcond[0]) > IKFAST_EVALCOND_THRESH  || IKabs(evalcond[1]) > IKFAST_EVALCOND_THRESH  || IKabs(evalcond[2]) > IKFAST_EVALCOND_THRESH  || IKabs(evalcond[3]) > IKFAST_EVALCOND_THRESH  )
{
continue;
}
}

{
std::vector<IkSingleDOFSolutionBase<IkReal> > vinfos(3);
vinfos[0].jointtype = 17;
vinfos[0].foffset = j0;
vinfos[0].indices[0] = _ij0[0];
vinfos[0].indices[1] = _ij0[1];
vinfos[0].maxsolutions = _nj0;
vinfos[1].jointtype = 1;
vinfos[1].foffset = j1;
vinfos[1].indices[0] = _ij1[0];
vinfos[1].indices[1] = _ij1[1];
vinfos[1].maxsolutions = _nj1;
vinfos[2].jointtype = 1;
vinfos[2].foffset = j2;
vinfos[2].indices[0] = _ij2[0];
vinfos[2].indices[1] = _ij2[1];
vinfos[2].maxsolutions = _nj2;
std::vector<int> vfree(0);
solutions.AddSolution(vinfos,vfree);
}
}
}
}
}

} else
{
continue; // verifyAllEquations

}

}
}
return solutions.GetNumSolutions()>0;
}
};


/// solves the inverse kinematics equations.
/// \param pfree is an array specifying the free joints of the chain.
IKFAST_API bool ComputeIk(const IkReal* eetrans, const IkReal* eerot, const IkReal* pfree, IkSolutionListBase<IkReal>& solutions) {
IKSolver solver;
return solver.ComputeIk(eetrans,eerot,pfree,solutions);
}

IKFAST_API bool ComputeIk2(const IkReal* eetrans, const IkReal* eerot, const IkReal* pfree, IkSolutionListBase<IkReal>& solutions, void* pOpenRAVEManip) {
IKSolver solver;
return solver.ComputeIk(eetrans,eerot,pfree,solutions);
}

IKFAST_API const char* GetKinematicsHash() { return "<robot:GenericRobot - myarm (6c33919e2bc0132812bfdd40147e9020)>"; }

IKFAST_API const char* GetIkFastVersion() { return "0x1000004a"; }

#ifdef IKFAST_NAMESPACE
} // end namespace
#endif

#ifndef IKFAST_NO_MAIN
#include <stdio.h>
#include <stdlib.h>
#ifdef IKFAST_NAMESPACE
using namespace IKFAST_NAMESPACE;
#endif
int main(int argc, char** argv)
{
    if( argc != 12+GetNumFreeParameters()+1 ) {
        printf("\nUsage: ./ik r00 r01 r02 t0 r10 r11 r12 t1 r20 r21 r22 t2 free0 ...\n\n"
               "Returns the ik solutions given the transformation of the end effector specified by\n"
               "a 3x3 rotation R (rXX), and a 3x1 translation (tX).\n"
               "There are %d free parameters that have to be specified.\n\n",GetNumFreeParameters());
        return 1;
    }

    IkSolutionList<IkReal> solutions;
    std::vector<IkReal> vfree(GetNumFreeParameters());
    IkReal eerot[9],eetrans[3];
    eerot[0] = atof(argv[1]); eerot[1] = atof(argv[2]); eerot[2] = atof(argv[3]); eetrans[0] = atof(argv[4]);
    eerot[3] = atof(argv[5]); eerot[4] = atof(argv[6]); eerot[5] = atof(argv[7]); eetrans[1] = atof(argv[8]);
    eerot[6] = atof(argv[9]); eerot[7] = atof(argv[10]); eerot[8] = atof(argv[11]); eetrans[2] = atof(argv[12]);
    for(std::size_t i = 0; i < vfree.size(); ++i)
        vfree[i] = atof(argv[13+i]);
    bool bSuccess = ComputeIk(eetrans, eerot, vfree.size() > 0 ? &vfree[0] : NULL, solutions);

    if( !bSuccess ) {
        fprintf(stderr,"Failed to get ik solution\n");
        return -1;
    }

    printf("Found %d ik solutions:\n", (int)solutions.GetNumSolutions());
    std::vector<IkReal> solvalues(GetNumJoints());
    for(std::size_t i = 0; i < solutions.GetNumSolutions(); ++i) {
        const IkSolutionBase<IkReal>& sol = solutions.GetSolution(i);
        printf("sol%d (free=%d): ", (int)i, (int)sol.GetFree().size());
        std::vector<IkReal> vsolfree(sol.GetFree().size());
        sol.GetSolution(&solvalues[0],vsolfree.size()>0?&vsolfree[0]:NULL);
        for( std::size_t j = 0; j < solvalues.size(); ++j)
            printf("%.15f, ", solvalues[j]);
        printf("\n");
    }
    return 0;
}

#endif