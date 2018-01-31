/****************************************************************************
 * Copyright (C) 2014-2017 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2008-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 **************************************************************************** 
 *
 ****************************************************************************/

#ifndef _DCE2_MEMORY_H_
#define _DCE2_MEMORY_H_

/********************************************************************
 * Enumerations
 ********************************************************************/
typedef enum _DCE2_MemType
{
    DCE2_MEM_TYPE__CONFIG,   /* Configuration */
    DCE2_MEM_TYPE__ROPTION,  /* Rule options */
    DCE2_MEM_TYPE__RT,       /* Routing tables */
    DCE2_MEM_TYPE__INIT,     /* Other initialization */
    DCE2_MEM_TYPE__SMB_SSN,  /* SMB session data */
    DCE2_MEM_TYPE__SMB_SEG,  /* SMB segmentation buffer */
    DCE2_MEM_TYPE__SMB_UID,  /* SMB uid tracking */
    DCE2_MEM_TYPE__SMB_TID,  /* SMB tid tracking */
    DCE2_MEM_TYPE__SMB_FID,  /* SMB fid tracking */
    DCE2_MEM_TYPE__SMB_FILE, /* SMB file tracking */
    DCE2_MEM_TYPE__SMB_REQ,  /* SMB request/response tracking */
    DCE2_MEM_TYPE__TCP_SSN,  /* TCP session data */
    DCE2_MEM_TYPE__CO_SEG,   /* TCP segmentation buffer */
    DCE2_MEM_TYPE__CO_FRAG,  /* TCP fragmentation data */
    DCE2_MEM_TYPE__CO_CTX,   /* TCP context tracking */
    DCE2_MEM_TYPE__UDP_SSN,  /* UDP session data */
    DCE2_MEM_TYPE__CL_ACT,   /* UDP activity tracking */
    DCE2_MEM_TYPE__CL_FRAG,  /* UDP fragment tracking */
    DCE2_MEM_TYPE__HTTP_SSN  /* HTTP session data */

} DCE2_MemType;

typedef enum _DCE2_MemState
{
    DCE2_MEM_STATE__OKAY,
    DCE2_MEM_STATE__MEMCAP

} DCE2_MemState;

/********************************************************************
 * Structures
 ********************************************************************/
typedef struct _DCE2_Memory
{
    u_int32_t total;
    u_int32_t total_max;
    u_int32_t rtotal;       /* Run time total */
    u_int32_t rtotal_max;
    u_int32_t config;
    u_int32_t config_max;
    u_int32_t roptions;
    u_int32_t roptions_max;
    u_int32_t rt;
    u_int32_t rt_max;
    u_int32_t init;
    u_int32_t init_max;

    u_int32_t smb_total;     /* total memory allocated for SMB */
    u_int32_t smb_total_max; /* max total memory allocated for SMB */
    u_int32_t smb_ssn;       /* amount allocated for session structures */
    u_int32_t smb_ssn_max;   /* max amount allocated for session structures */
    u_int32_t smb_seg;       /* amount allocated for segmentation buffers */
    u_int32_t smb_seg_max;   /* max amount allocated for segmentation buffers */
    u_int32_t smb_uid;       /* amount allocated for uid tracking */
    u_int32_t smb_uid_max;   /* max amount allocated for uid tracking */
    u_int32_t smb_tid;       /* amount allocated for tid tracking */
    u_int32_t smb_tid_max;   /* max amount allocated for tid tracking */
    u_int32_t smb_fid;       /* amount allocated for fid tracking */
    u_int32_t smb_fid_max;   /* max amount allocated for fid tracking */
    u_int32_t smb_file;      /* amount allocated for file tracking */
    u_int32_t smb_file_max;  /* max amount allocated for file tracking */
    u_int32_t smb_req;       /* amount allocated for request tracking */
    u_int32_t smb_req_max;   /* max amount allocated for request tracking */

    u_int32_t tcp_total;     /* total memory allocated for TCP */
    u_int32_t tcp_total_max; /* max total memory allocated for TCP */
    u_int32_t tcp_ssn;       /* amount allocated for session structures */
    u_int32_t tcp_ssn_max;   /* max amount allocated for session structures */

    u_int32_t udp_total;     /* total memory allocated for UDP */
    u_int32_t udp_total_max; /* max total memory allocated for UDP */
    u_int32_t udp_ssn;       /* amount allocated for session structures */
    u_int32_t udp_ssn_max;   /* max amount allocated for session structures */

    u_int32_t http_total;     /* total memory allocated for UDP */
    u_int32_t http_total_max; /* max total memory allocated for UDP */
    u_int32_t http_ssn;       /* amount allocated for session structures */
    u_int32_t http_ssn_max;   /* max amount allocated for session structures */

    u_int32_t co_total;     /* total memory allocated for CO */
    u_int32_t co_total_max; /* max total memory allocated for CO */
    u_int32_t co_seg;       /* amount allocated for segmentation */
    u_int32_t co_seg_max;   /* max amount allocated for segmentation */
    u_int32_t co_frag;      /* amount allocated for frag tracking */
    u_int32_t co_frag_max;  /* max amount allocated for frag tracking */
    u_int32_t co_ctx;       /* amount allocated for contexts */
    u_int32_t co_ctx_max;   /* max amount allocated for contexts */

    u_int32_t cl_total;     /* total memory allocated for CL */
    u_int32_t cl_total_max; /* max total memory allocated for CL */
    u_int32_t cl_act;       /* amount allocated for activity trackers */
    u_int32_t cl_act_max;   /* max amount allocated for activity trackers */
    u_int32_t cl_frag;      /* amount allocated for frag tracking */
    u_int32_t cl_frag_max;  /* max amount allocated for frag tracking */

} DCE2_Memory;

/********************************************************************
 * Extern variables
 ********************************************************************/
extern DCE2_Memory dce2_memory;
extern DCE2_MemState dce2_mem_state;

/********************************************************************
 * Public functions
 ********************************************************************/
void DCE2_RegMem(u_int32_t, DCE2_MemType);
void DCE2_UnRegMem(u_int32_t, DCE2_MemType);
void * DCE2_Alloc(u_int32_t, DCE2_MemType);
void DCE2_Free(void *, u_int32_t, DCE2_MemType);
void * DCE2_ReAlloc(void *, u_int32_t, u_int32_t, DCE2_MemType);
void DCE2_FreeAll(void);
void DCE2_MemInit(void);
size_t DCE2_MemInUse();

#endif   /* _DCE2_MEMORY_H_ */

