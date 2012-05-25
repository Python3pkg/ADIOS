/* 
 * ADIOS is freely available under the terms of the BSD license described
 * in the COPYING file in the top level directory of this source distribution.
 *
 * Copyright (c) 2008 - 2009.  UT-BATTELLE, LLC. All rights reserved.
 */

#include <stdlib.h>
#include <string.h>
#include "public/adios_read_v2.h"
#include "public/adios_error.h"
#include "core/common_read.h"
#define BYTE_ALIGN 8


const char *adios_errmsg ()
{
    return adios_get_last_errmsg();
}

int adios_read_init_method (enum ADIOS_READ_METHOD method, MPI_Comm comm, const char * parameters)
{
    return common_read_init_method (method,comm,parameters);
} 

int adios_read_finalize_method(enum ADIOS_READ_METHOD method)
{
    return common_read_finalize_method(method);
}

ADIOS_FILE * adios_read_open_stream (const char * fname,
                                     enum ADIOS_READ_METHOD method,
                                     MPI_Comm comm,
                                     enum ADIOS_LOCKMODE lock_mode,
                                     int timeout_msec)
{
    return common_read_open_stream (fname, method, comm, lock_mode, timeout_msec);
}

ADIOS_FILE * adios_read_open_file (const char * fname,
                                   enum ADIOS_READ_METHOD method,
                                   MPI_Comm comm)
{
    return common_read_open_file (fname, method, comm);
}

int adios_read_close (ADIOS_FILE *fp) 
{
    return common_read_close (fp);
}

int adios_advance_step (ADIOS_FILE *fp, int last, int wait_for_step)
{
    return common_read_advance_step (fp, last, wait_for_step);
}

void adios_release_step (ADIOS_FILE *fp)
{
    common_read_release_step (fp);
}

ADIOS_VARINFO * adios_inq_var (ADIOS_FILE  *fp, const char * varname) 
{
    return common_read_inq_var (fp, varname);
}

ADIOS_VARINFO * adios_inq_var_byid (ADIOS_FILE  *fp, int varid)
{
    return common_read_inq_var_byid (fp, varid);
}

void adios_free_varinfo (ADIOS_VARINFO *vp)
{
    common_read_free_varinfo (vp);
}

int adios_inq_var_stat (ADIOS_FILE *fp, ADIOS_VARINFO * varinfo,
                                    int per_step_stat, int per_writer_stat)
{
    return common_read_inq_var_stat (fp, varinfo, per_step_stat, per_writer_stat);
}

int adios_inq_var_blockinfo (ADIOS_FILE *fp, ADIOS_VARINFO * varinfo)
{
    return common_read_inq_var_blockinfo (fp, varinfo);
}

int adios_schedule_read (const ADIOS_FILE      * fp,
                             const ADIOS_SELECTION * sel,
                             const char            * varname,
                             int                     from_steps,
                             int                     nsteps,
                             void                  * data)
{
    return common_read_schedule_read (fp, sel, varname, from_steps, nsteps, data);
}

int adios_schedule_read_byid (const ADIOS_FILE      * fp,
                                  const ADIOS_SELECTION * sel,
                                  int                     varid,
                                  int                     from_steps,
                                  int                     nsteps,
                                  void                  * data)
{
    return common_read_schedule_read_byid (fp, sel, varid, from_steps, nsteps, data);
}

int adios_perform_reads (const ADIOS_FILE *fp, int blocking)
{
    return common_read_perform_reads (fp, blocking);
}

int adios_check_reads (const ADIOS_FILE * fp, ADIOS_VARCHUNK ** chunk)
{
    return common_read_check_reads (fp, chunk);
}

void adios_free_chunk (ADIOS_VARCHUNK *chunk)
{
    common_read_free_chunk (chunk);
}

int adios_get_attr (ADIOS_FILE  * fp, const char * attrname, enum ADIOS_DATATYPES * type,
                    int * size, void ** data)
{
    return common_read_get_attr (fp, attrname, type, size, data);
}

int adios_get_attr_byid (ADIOS_FILE  * fp, int attrid, 
                    enum ADIOS_DATATYPES * type, int * size, void ** data)
{
    return common_read_get_attr_byid (fp, attrid, type, size, data);
}

const char * adios_type_to_string (enum ADIOS_DATATYPES type)
{
    return common_read_type_to_string (type);
}

int adios_type_size(enum ADIOS_DATATYPES type, void *data)
{
    return common_read_type_size(type, data);
}

int adios_get_grouplist (ADIOS_FILE  *fp, char **group_namelist)
{
    return common_read_get_grouplist (fp, group_namelist);
}

int adios_group_view (ADIOS_FILE  *fp, int groupid)
{
    return common_read_group_view (fp, groupid);
}

/*
void adios_print_groupinfo (ADIOS_FILE  *fp) 
{
    common_read_print_groupinfo(fp);
}


void adios_print_fileinfo (ADIOS_FILE *fp) 
{
    common_read_print_fileinfo(fp);
}
*/

