#ifndef PLOTFILEUTIL_H_
#define PLOTFILEUTIL_H_

#include <string>

#include <Geometry.H>
#include <MultiFab.H>

namespace BoxLib
{
    // ---- return the name of the level directory,  e.g., Level_5
    std::string LevelPath (int level, const std::string &levelPrefix = "Level_");

    // ---- return the path of the multifab to write to the header, e.g., Level_5/Cell
    std::string MultiFabHeaderPath (int level,
                                    const std::string &levelPrefix = "Level_",
                                    const std::string &mfPrefix = "Cell");

    // ---- return the full path of the level directory, e.g., plt00005/Level_5
    std::string LevelFullPath (int level,
                               const std::string &plotfilename,
                               const std::string &levelPrefix = "Level_");

    // ---- return the full path multifab prefix, e.g., plt00005/Level_5/Cell
    std::string MultiFabFileFullPrefix (int level,
                                        const std::string &plotfilename,
                                        const std::string &levelPrefix = "Level_",
					const std::string &mfPrefix = "Cell");

    // ---- prebuild a hierarchy of directories
    // ---- dirName is built first.  if dirName exists, it is renamed.  then build
    // ---- dirName/subDirPrefix_0 .. dirName/subDirPrefix_nSubDirs-1
    // ---- if callBarrier is true, call ParallelDescriptor::Barrier()
    // ---- after all directories are built
    // ---- ParallelDescriptor::IOProcessor() creates the directories
    void PreBuildDirectorHierarchy (const std::string &dirName,
                                    const std::string &subDirPrefix,
				    int nSubDirs,
				    bool callBarrier);

    // ---- write a generic plot file header to the file plotfilename/Header
    // ---- the plotfilename directory must already exist
    void WriteGenericPlotfileHeader (std::ostream &HeaderFile,
                                     int nlevels,
				     const Array<BoxArray> &bArray,
				     const Array<std::string> &varnames,
				     const Array<Geometry> &geom,
				     Real time,
				     const Array<int> &level_steps,
				     const Array<IntVect> &ref_ratio,
				     const std::string &versionName = "HyperCLaw-V1.1",
				     const std::string &levelPrefix = "Level_",
				     const std::string &mfPrefix = "Cell");

    void WriteSingleLevelPlotfile (const std::string &plotfilename,
				   const MultiFab &mf,
				   const Array<std::string> &varnames,
				   const Geometry &geom,
				   Real t,
				   int level_step);

    void WriteMultiLevelPlotfile (const std::string &plotfilename,
                                  int nlevels,
				  const Array<const MultiFab*> &mf,
				  const Array<std::string> &varnames,
				  const Array<Geometry> &geom,
				  Real time,
				  const Array<int> &level_steps,
				  const Array<IntVect> &ref_ratio);
}

#endif
