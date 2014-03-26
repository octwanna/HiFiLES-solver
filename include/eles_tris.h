/*!
 * \file eles_tris.h
 * \brief _____________________________
 * \author - Original code: SD++ developed by Patrice Castonguay, Antony Jameson,
 *                          Peter Vincent, David Williams (alphabetical by surname).
 *         - Current development: Aerospace Computing Laboratory (ACL) directed
 *                                by Prof. Jameson. (Aero/Astro Dept. Stanford University).
 * \version 1.0.0
 *
 * HiFiLES (High Fidelity Large Eddy Simulation).
 * Copyright (C) 2013 Aerospace Computing Laboratory.
 */

#pragma once

#include "eles.h"
#include "array.h"

class eles_tris: public eles
{	
public:

  // #### constructors ####

  // default constructor

  eles_tris();

  // #### methods ####

  /*! set shape */
  //void set_shape(array<int> &in_n_spts_per_ele);

  void set_connectivity_plot();

  /*! set location of solution points */
  void set_loc_upts(void);

  /*! set location of flux points */
  void set_tloc_fpts(void);

  /*! set location and weights of interface cubature points */
  void set_inters_cubpts(void);

  /*! set location and weights of volume cubature points */
  void set_volume_cubpts(void);

  /*! set location of plot points */
  void set_loc_ppts(void);

  /*! set location of shape points */
  //	void set_loc_spts(void);

  /*! set transformed normals at flux points */
  void set_tnorm_fpts(void);

  //#### helper methods ####

  void setup_ele_type_specific(void);

  /*! read restart info */
  int read_restart_info(ifstream& restart_file);

  /*! write restart info */
  void write_restart_info(ofstream& restart_file);

  /*! Compute interface jacobian determinant on face */
  double compute_inter_detjac_inters_cubpts(int in_inter, array<double> d_pos);

  /*! evaluate nodal basis */
  double eval_nodal_basis(int in_index, array<double> in_loc);

  /*! evaluate nodal basis for restart file*/
  double eval_nodal_basis_restart(int in_index, array<double> in_loc);

  /*! evaluate derivative of nodal basis */
  double eval_d_nodal_basis(int in_index, int in_cpnt, array<double> in_loc);

  /*! evaluate divergence of vcjh basis */
  //double eval_div_vcjh_basis(int in_index, array<double>& loc);

  void fill_opp_3(array<double>& opp_3);

  /*! evaluate nodal shape basis */
  double eval_nodal_s_basis(int in_index, array<double> in_loc, int in_n_spts);

  /*! evaluate derivative of nodal shape basis */
  void eval_d_nodal_s_basis(array<double> &d_nodal_s_basis, array<double> in_loc, int in_n_spts);

  /*! evaluate second derivative of nodal shape basis */
  void eval_dd_nodal_s_basis(array<double> &dd_nodal_s_basis, array<double> in_loc, int in_n_spts);

  /*! Compute the filter matrix for subgrid-scale models */
  void compute_filter_upts(void);

  /*! Calculate element volume */
  double calc_ele_vol(double& detjac);

  /*! Element reference length calculation */
  double calc_h_ref_specific(int in_ele);

protected:

  // methods
  void set_vandermonde();
  void set_vandermonde_restart();

  // members
  array<double> vandermonde;
  array<double> vandermonde_rest;
  array<double> inv_vandermonde;
  array<double> inv_vandermonde_rest;

  array<double> loc_1d_fpts;

};
