/**********************************************************\
|                   libmv numerical types                  |
\**********************************************************/
//Here is a change from classic libmv:
//In order to have something which tell us this is
//the core libmv library, numerical.h is now renamed to
//libmv_types.h *but the content is not modified*

//Added _CORE_ in define to remind us it's not libmv full library.
#ifndef LIBMV_CORE_NUMERIC_NUMERIC_H
#define LIBMV_CORE_NUMERIC_NUMERIC_H

//define LIBMV_API_EXPORTS when you want to create the library...

#if (defined WIN32 || defined _WIN32 || defined WINCE) && defined LIBMV_API_EXPORTS
#define _LIBMV_DLL_ __declspec(dllexport)
#else
#define _LIBMV_DLL_ __declspec(dllimport)
#endif

//////////////////////////////////////////////////////////////////////////
//Logging hack before having a consensus around with system is needed!
#include <iostream>

#ifdef ERROR
#undef ERROR
#endif
const int INFO = 0, WARNING = 1, ERROR = 2, FATAL = 3, NUM_SEVERITIES = 4;

#define LOG(x) std::cout << x
#define VLOG(x) std::cout << x
#define CHECK(x) assert(x)

//////////////////////////////////////////////////////////////////////////

#include <Eigen/Cholesky>
#include <Eigen/Core>
#include <Eigen/Eigenvalues> 
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <Eigen/QR>
#include <Eigen/SVD>

#if _WIN32 || __APPLE__
void static sincos (double x, double *sinx, double *cosx) {
  *sinx = sin(x);
  *cosx = cos(x);
}
#endif //_WIN32 || __APPLE__

#if _WIN32
inline long lround(double d) {
  return (long)(d>0 ? d+0.5 : ceil(d-0.5));
}
inline int round(double d) {
  return (d>0) ? int(d+0.5) : int(d-0.5);
}
typedef unsigned int uint;
#endif //_WIN32

namespace libmv {
  //(Thibault) I didn't remove unused types as this header will probably
  //be used in full libmv lib in the future.
  typedef Eigen::MatrixXd Mat;
  typedef Eigen::VectorXd Vec;

  typedef Eigen::MatrixXf Matf;
  typedef Eigen::VectorXf Vecf;

  typedef Eigen::Matrix<unsigned int, Eigen::Dynamic, Eigen::Dynamic> Matu;
  typedef Eigen::Matrix<unsigned int, Eigen::Dynamic, 1> Vecu;
  typedef Eigen::Matrix<unsigned int, 2, 1> Vec2u;

  typedef Eigen::Matrix<double, 2, 2> Mat2;
  typedef Eigen::Matrix<double, 2, 3> Mat23;
  typedef Eigen::Matrix<double, 3, 3> Mat3;
  typedef Eigen::Matrix<double, 3, 4> Mat34;
  typedef Eigen::Matrix<double, 3, 5> Mat35;
  typedef Eigen::Matrix<double, 4, 1> Mat41;
  typedef Eigen::Matrix<double, 4, 3> Mat43;
  typedef Eigen::Matrix<double, 4, 4> Mat4;
  typedef Eigen::Matrix<double, 4, 6> Mat46;
  typedef Eigen::Matrix<float, 2, 2> Mat2f;
  typedef Eigen::Matrix<float, 2, 3> Mat23f;
  typedef Eigen::Matrix<float, 3, 3> Mat3f;
  typedef Eigen::Matrix<float, 3, 4> Mat34f;
  typedef Eigen::Matrix<float, 3, 5> Mat35f;
  typedef Eigen::Matrix<float, 4, 3> Mat43f;
  typedef Eigen::Matrix<float, 4, 4> Mat4f;
  typedef Eigen::Matrix<float, 4, 6> Mat46f;

  typedef Eigen::Matrix<double, 3, 3, Eigen::RowMajor> RMat3;
  typedef Eigen::Matrix<double, 4, 4, Eigen::RowMajor> RMat4;

  typedef Eigen::Matrix<double, 2, Eigen::Dynamic> Mat2X;
  typedef Eigen::Matrix<double, 3, Eigen::Dynamic> Mat3X;
  typedef Eigen::Matrix<double, 4, Eigen::Dynamic> Mat4X;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 2> MatX2;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 3> MatX3;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 4> MatX4;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 5> MatX5;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 6> MatX6;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 7> MatX7;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 8> MatX8;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 9> MatX9;
  typedef Eigen::Matrix<double, Eigen::Dynamic,15> MatX15;
  typedef Eigen::Matrix<double, Eigen::Dynamic,16> MatX16;

  typedef Eigen::Vector2d Vec2;
  typedef Eigen::Vector3d Vec3;
  typedef Eigen::Vector4d Vec4;
  typedef Eigen::Matrix<double, 5, 1>  Vec5;
  typedef Eigen::Matrix<double, 6, 1>  Vec6;
  typedef Eigen::Matrix<double, 7, 1>  Vec7;
  typedef Eigen::Matrix<double, 8, 1>  Vec8;
  typedef Eigen::Matrix<double, 9, 1>  Vec9;
  typedef Eigen::Matrix<double, 10, 1> Vec10;
  typedef Eigen::Matrix<double, 11, 1> Vec11;
  typedef Eigen::Matrix<double, 12, 1> Vec12;
  typedef Eigen::Matrix<double, 13, 1> Vec13;
  typedef Eigen::Matrix<double, 14, 1> Vec14;
  typedef Eigen::Matrix<double, 15, 1> Vec15;
  typedef Eigen::Matrix<double, 16, 1> Vec16;
  typedef Eigen::Matrix<double, 17, 1> Vec17;
  typedef Eigen::Matrix<double, 18, 1> Vec18;
  typedef Eigen::Matrix<double, 19, 1> Vec19;
  typedef Eigen::Matrix<double, 20, 1> Vec20;

  typedef Eigen::Vector2f Vec2f;
  typedef Eigen::Vector3f Vec3f;
  typedef Eigen::Vector4f Vec4f;

  typedef Eigen::VectorXi VecXi;

  typedef Eigen::Vector2i Vec2i;
  typedef Eigen::Vector3i Vec3i;
  typedef Eigen::Vector4i Vec4i;

  typedef Eigen::Matrix<float,
    Eigen::Dynamic,
    Eigen::Dynamic,
    Eigen::RowMajor> RMatf;

  typedef Eigen::NumTraits<double> EigenDouble;

  using Eigen::Map;
  using Eigen::Dynamic;
  using Eigen::Matrix;

  /*
  Why this??? 
  See with libmv if we can remove this!
  // Find U, s, and VT such that
  //
  //   A = U * diag(s) * VT
  //
  template <typename TMat, typename TVec>
  inline void SVD(TMat *A, Vec *s, Mat *U, Mat *VT) {
  assert(0);
  }
  */

  // Solve the linear system Ax = 0 via SVD. Store the solution in x, such that
  // ||x|| = 1.0. Return the singluar value corresponding to the solution.
  // Destroys A and resizes x if necessary.
  // TODO(maclean): Take the SVD of the transpose instead of this zero padding.
  template <typename TMat, typename TVec>
  double Nullspace(TMat *A, TVec *nullspace) {
    Eigen::JacobiSVD<TMat> svd(*A, Eigen::ComputeFullV);
    (*nullspace) = svd.matrixV().col(A->cols()-1);
    if (A->rows() >= A->cols())
      return svd.singularValues()(A->cols()-1);
    else
      return 0.0;
  }

  // Solve the linear system Ax = 0 via SVD. Finds two solutions, x1 and x2, such
  // that x1 is the best solution and x2 is the next best solution (in the L2
  // norm sense). Store the solution in x1 and x2, such that ||x|| = 1.0. Return
  // the singluar value corresponding to the solution x1.  Destroys A and resizes
  // x if necessary.
  template <typename TMat, typename TVec1, typename TVec2>
  double Nullspace2(TMat *A, TVec1 *x1, TVec2 *x2) {
    Eigen::JacobiSVD<TMat> svd(*A, Eigen::ComputeFullV);
    *x1 = svd.matrixV().col(A->cols() - 1);
    *x2 = svd.matrixV().col(A->cols() - 2);
    if (A->rows() >= A->cols())
      return svd.singularValues()(A->cols()-1);
    else
      return 0.0;
  }

  // In place transpose for square matrices.
  template<class TA>
  inline void TransposeInPlace(TA *A) {
    *A = A->transpose().eval();
  }

  template<typename TVec>
  inline double NormL1(const TVec &x) {
    return x.array().abs().sum();
  }

  template<typename TVec>
  inline double NormL2(const TVec &x) {
    return x.norm();
  }

  template<typename TVec>
  inline double NormLInfinity(const TVec &x) {
    return x.array().abs().maxCoeff();
  }

  template<typename TVec>
  inline double DistanceL1(const TVec &x, const TVec &y) {
    return (x - y).array().abs().sum();
  }

  template<typename TVec>
  inline double DistanceL2(const TVec &x, const TVec &y) {
    return (x - y).norm();
  }
  template<typename TVec>
  inline double DistanceLInfinity(const TVec &x, const TVec &y) {
    return (x - y).array().abs().maxCoeff();
  }

  // Normalize a vector with the L1 norm, and return the norm before it was
  // normalized.
  template<typename TVec>
  inline double NormalizeL1(TVec *x) {
    double norm = NormL1(*x);
    *x /= norm;
    return norm;
  }

  // Normalize a vector with the L2 norm, and return the norm before it was
  // normalized.
  template<typename TVec>
  inline double NormalizeL2(TVec *x) {
    double norm = NormL2(*x);
    *x /= norm;
    return norm;
  }

  // Normalize a vector with the L^Infinity norm, and return the norm before it
  // was normalized.
  template<typename TVec>
  inline double NormalizeLInfinity(TVec *x) {
    double norm = NormLInfinity(*x);
    *x /= norm;
    return norm;
  }

  // Return the square of a number.
  template<typename T>
  inline T Square(T x) {
    return x * x;
  }

  Mat3 _LIBMV_DLL_ RotationAroundX(double angle);
  Mat3 _LIBMV_DLL_ RotationAroundY(double angle);
  Mat3 _LIBMV_DLL_ RotationAroundZ(double angle);

  // Returns the rotation matrix of a rotation of angle |axis| around axis.
  // This is computed using the Rodrigues formula, see:
  //  http://mathworld.wolfram.com/RodriguesRotationFormula.html
  Mat3 _LIBMV_DLL_ RotationRodrigues(const Vec3 &axis);

  // Make a rotation matrix such that center becomes the direction of the
  // positive z-axis, and y is oriented close to up.
  Mat3 _LIBMV_DLL_ LookAt(Vec3 center);

  // Return a diagonal matrix from a vector containg the diagonal values.
  template <typename TVec>
  inline Mat Diag(const TVec &x) {
    return x.asDiagonal();
  }

  template<typename TMat>
  inline double FrobeniusNorm(const TMat &A) {
    return sqrt(A.array().abs2().sum());
  }

  template<typename TMat>
  inline double FrobeniusDistance(const TMat &A, const TMat &B) {
    return FrobeniusNorm(A - B);
  }

  inline Vec3 CrossProduct(const Vec3 &x, const Vec3 &y) {
    return x.cross(y);
  }

  Mat3 _LIBMV_DLL_ CrossProductMatrix(const Vec3 &x);

  void _LIBMV_DLL_ MeanAndVarianceAlongRows(const Mat &A,
    Vec *mean_pointer,
    Vec *variance_pointer);

#if _WIN32
  // TODO(bomboze): un-#if this for both platforms once tested under Windows
  /* This solution was extensively discussed here http://forum.kde.org/viewtopic.php?f=74&t=61940 */
#define SUM_OR_DYNAMIC(x,y) (x==Eigen::Dynamic||y==Eigen::Dynamic)?Eigen::Dynamic:(x+y)

  template<typename Derived1, typename Derived2>
  struct hstack_return {
    typedef typename Derived1::Scalar Scalar;
    enum {
      RowsAtCompileTime = Derived1::RowsAtCompileTime,
      ColsAtCompileTime = SUM_OR_DYNAMIC(Derived1::ColsAtCompileTime, Derived2::ColsAtCompileTime),
      Options = Derived1::Flags&Eigen::RowMajorBit ? Eigen::RowMajor : 0,
      MaxRowsAtCompileTime = Derived1::MaxRowsAtCompileTime,
      MaxColsAtCompileTime = SUM_OR_DYNAMIC(Derived1::MaxColsAtCompileTime, Derived2::MaxColsAtCompileTime)
    };
    typedef Eigen::Matrix<Scalar,
      RowsAtCompileTime,
      ColsAtCompileTime,
      Options,
      MaxRowsAtCompileTime,
      MaxColsAtCompileTime> type;
  };

  template<typename Derived1, typename Derived2>
  typename hstack_return<Derived1,Derived2>::type
    HStack (const Eigen::MatrixBase<Derived1>& lhs, const Eigen::MatrixBase<Derived2>& rhs) {
      typename hstack_return<Derived1,Derived2>::type res;
      res.resize(lhs.rows(), lhs.cols()+rhs.cols());
      res << lhs, rhs;
      return res;
  };


  template<typename Derived1, typename Derived2>
  struct vstack_return {
    typedef typename Derived1::Scalar Scalar;
    enum {
      RowsAtCompileTime = SUM_OR_DYNAMIC(Derived1::RowsAtCompileTime, Derived2::RowsAtCompileTime),
      ColsAtCompileTime = Derived1::ColsAtCompileTime,
      Options = Derived1::Flags&Eigen::RowMajorBit ? Eigen::RowMajor : 0,
      MaxRowsAtCompileTime = SUM_OR_DYNAMIC(Derived1::MaxRowsAtCompileTime, Derived2::MaxRowsAtCompileTime),
      MaxColsAtCompileTime = Derived1::MaxColsAtCompileTime
    };
    typedef Eigen::Matrix<Scalar,
      RowsAtCompileTime,
      ColsAtCompileTime,
      Options,
      MaxRowsAtCompileTime,
      MaxColsAtCompileTime> type;
  };

  template<typename Derived1, typename Derived2>
  typename vstack_return<Derived1,Derived2>::type
    VStack (const Eigen::MatrixBase<Derived1>& lhs, const Eigen::MatrixBase<Derived2>& rhs) {
      typename vstack_return<Derived1,Derived2>::type res;
      res.resize(lhs.rows()+rhs.rows(), lhs.cols());
      res << lhs, rhs;
      return res;
  };


#else //_WIN32

  // Since it is not possible to typedef privately here, use a macro.
  // Always take dynamic columns if either side is dynamic.
#define COLS \
  ((ColsLeft == Eigen::Dynamic || ColsRight == Eigen::Dynamic) \
  ? Eigen::Dynamic : (ColsLeft + ColsRight))

  // Same as above, except that prefer fixed size if either is fixed.
#define ROWS \
  ((RowsLeft == Eigen::Dynamic && RowsRight == Eigen::Dynamic) \
  ? Eigen::Dynamic \
  : ((RowsLeft == Eigen::Dynamic) \
  ? RowsRight \
  : RowsLeft \
  ) \
  )

  // TODO(keir): Add a static assert if both rows are at compiletime.
  template<typename T, int RowsLeft, int RowsRight, int ColsLeft, int ColsRight>
  Eigen::Matrix<T, ROWS, COLS>
    HStack(const Eigen::Matrix<T, RowsLeft,  ColsLeft>  &left,
    const Eigen::Matrix<T, RowsRight, ColsRight> &right) {
      assert(left.rows() == right.rows());
      int n = left.rows();
      int m1 = left.cols();
      int m2 = right.cols();

      Eigen::Matrix<T, ROWS, COLS> stacked(n, m1 + m2);
      stacked.block(0, 0,  n, m1) = left;
      stacked.block(0, m1, n, m2) = right;
      return stacked;
  }

  // Reuse the above macros by swapping the order of Rows and Cols. Nasty, but
  // the duplication is worse.
  // TODO(keir): Add a static assert if both rows are at compiletime.
  // TODO(keir): Mail eigen list about making this work for general expressions
  // rather than only matrix types.
  template<typename T, int RowsLeft, int RowsRight, int ColsLeft, int ColsRight>
  Eigen::Matrix<T, COLS, ROWS>
    VStack(const Eigen::Matrix<T, ColsLeft,  RowsLeft>  &top,
    const Eigen::Matrix<T, ColsRight, RowsRight> &bottom) {
      assert(top.cols() == bottom.cols());
      int n1 = top.rows();
      int n2 = bottom.rows();
      int m = top.cols();

      Eigen::Matrix<T, COLS, ROWS> stacked(n1 + n2, m);
      stacked.block(0,  0, n1, m) = top;
      stacked.block(n1, 0, n2, m) = bottom;
      return stacked;
  }
#undef COLS
#undef ROWS
#endif //_WIN32



  void _LIBMV_DLL_ HorizontalStack(const Mat &left, const Mat &right, Mat *stacked);

  template<typename TTop, typename TBot, typename TStacked>
  void VerticalStack(const TTop &top, const TBot &bottom, TStacked *stacked) {
    assert(top.cols() == bottom.cols());
    int n1 = top.rows();
    int n2 = bottom.rows();
    int m = top.cols();

    stacked->resize(n1 + n2, m);
    stacked->block(0,  0, n1, m) = top;
    stacked->block(n1, 0, n2, m) = bottom;
  }

  void _LIBMV_DLL_ MatrixColumn(const Mat &A, int i, Vec2 *v);
  void _LIBMV_DLL_ MatrixColumn(const Mat &A, int i, Vec3 *v);
  void _LIBMV_DLL_ MatrixColumn(const Mat &A, int i, Vec4 *v);

  template <typename TMat, typename TCols>
  TMat ExtractColumns(const TMat &A, const TCols &columns) {
    TMat compressed(A.rows(), columns.size());
    for (int i = 0; i < columns.size(); ++i) {
      compressed.col(i) = A.col(columns[i]);
    }
    return compressed;
  }

  template <typename TMat, typename TDest>
  void reshape(const TMat &a, int rows, int cols, TDest *b) {
    assert(a.rows()*a.cols() == rows*cols);
    b->resize(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        (*b)(i, j) = a[cols*i + j];
      }
    }
  }

  inline bool isnan(double i) {
#ifdef WIN32
    return _isnan(i) > 0;
#else
    return std::isnan(i);
#endif
  }

  /// Ceil function that has the same behaviour for positive 
  /// and negative values
  template <typename FloatType>
  FloatType ceil0(const FloatType& value) {
    FloatType result = std::ceil( std::fabs( value ) );
    return (value < 0.0) ? -result : result;
  }

  /// Returns the skew anti-symmetric matrix of a vector
  inline Mat3 SkewMat(const Vec3 &x) {
    Mat3 skew;
    skew <<   0 ,-x(2), x(1),
      x(2),   0 ,-x(0),
      -x(1), x(0),    0;
    return skew;
  }
  /// Returns the skew anti-symmetric matrix of a vector with only
  /// the first two (independent) lines
  inline Mat23 SkewMatMinimal(const Vec2 &x) {
    Mat23 skew;
    skew << 0,-1, x(1),
      1, 0 -x(0);
    return skew;
  }

  //Move this libmv/numeric and add tests.
  //! (Thibault) moved from focal_from_fundamental.cc !
  template<class Tf, typename T>
  T GoldenRatioSearch(const Tf &f, T a, T b, T tol, int max_it) {
    // Golden ration search.
    double c = a + 0.618033988 * (b - a);
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    for (int i = 0; i < max_it && fabs(a - b) >= tol; ++i) {
      VLOG(3) << "a: " << a << " b: " << b << " c: " << c << " fc: " << fc << "\n";

      double d = a + 0.618033988 * (c - a);
      double fd = f(d);
      if (fd < fc) {
        b = c; fb = fc;
        c = d; fc = fd;
      } else {
        a = b; fa = fb;
        b = d; fb = fd;
      }
    }
    return c;
  }

  //TODO(pau) Move this to libmv/numeric and add tests.
  //! (Thibault) moved from focal_from_fundamental.cc !
  static double Lerp(double x, double x0, double y0, double x1, double y1) {
    return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
  }
} // namespace libmv

#endif  // LIBMV_NUMERIC_NUMERIC_H
