/* ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Project:
 *  sratools command line tool
 *
 * Purpose:
 *  locate executable
 *
 */

#pragma once
#include "opt_string.hpp"

namespace sratools {

    /// @brief like shell `which` but checks more than just PATH
    ///
    /// @param name executable name
    /// @param allowNotFound return empty string if not found, else print message and exit
    /// @param isaSraTool the executable is part of the SRA toolkit, effects message if not found
    ///
    /// @returns full path to executable if found
    extern
    opt_string which(std::string const &runpath, std::string const &name, bool allowNotFound = true, bool isaSraTool = false);

    /// @brief like shell `which` but checks more than just PATH
    ///
    /// @param runas_name user-friendly executable name, e.g. fastq-dump
    /// @param real_name real executable name, e.g. fastq-dump-orig
    /// @param version version to be appended to name, e.g. 2.10.0
    ///
    /// @returns full path to executable if found
    extern
    opt_string which(std::string const &runpath, std::string const &runas_name, std::string const &real_name, std::string const &version);

    /// @brief prints help message for failing to find an executable
    extern
    void pathHelp [[noreturn]] (std::string const &toolname, bool isaSraTool);

} // namespace sratools
