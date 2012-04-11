/* -*- c++ -*- */
/*
 * Copyright 2012 Free Software Foundation, Inc.
 * Copyright 2012 Dimitri Stolnikov <horiz0n@gmx.net>
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <osmosdr_source_c_impl.h>
#include <gr_io_signature.h>

/*
 * Create a new instance of osmosdr_source_c_impl and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
osmosdr_source_c_sptr
osmosdr_make_source_c (const std::string &args)
{
  return gnuradio::get_initial_sptr(new osmosdr_source_c_impl (args));
}

/*
 * Specify constraints on number of input and output streams.
 * This info is used to construct the input and output signatures
 * (2nd & 3rd args to gr_block's constructor).  The input and
 * output signatures are used by the runtime system to
 * check that a valid number and type of inputs and outputs
 * are connected to this block.  In this case, we accept
 * only 1 input and 1 output.
 */
static const int MIN_IN = 0;	// mininum number of input streams
static const int MAX_IN = 0;	// maximum number of input streams
static const int MIN_OUT = 1;	// minimum number of output streams
static const int MAX_OUT = 1;	// maximum number of output streams

/*
 * The private constructor
 */
osmosdr_source_c_impl::osmosdr_source_c_impl (const std::string &args)
  : gr_hier_block2 ("osmosdr_source_c_impl",
        gr_make_io_signature (MIN_IN, MAX_IN, sizeof (gr_complex)),
        gr_make_io_signature (MIN_OUT, MAX_OUT, sizeof (gr_complex)))
{
  _src = make_rtl_source_c( args );

  connect(_src, 0, self(), 0);
}

size_t osmosdr_source_c_impl::get_num_channels()
{
  return _src->get_num_channels();
}

osmosdr::meta_range_t osmosdr_source_c_impl::get_sample_rates()
{
  return _src->get_sample_rates();
}

double osmosdr_source_c_impl::set_sample_rate(double rate)
{
  return _src->set_sample_rate(rate);
}

double osmosdr_source_c_impl::get_sample_rate()
{
  return _src->get_sample_rate();
}

osmosdr::freq_range_t osmosdr_source_c_impl::get_freq_range( size_t chan )
{
  return _src->get_freq_range( chan );
}

double osmosdr_source_c_impl::set_center_freq( double freq, size_t chan )
{
  return _src->set_center_freq( freq, chan );
}

double osmosdr_source_c_impl::get_center_freq( size_t chan )
{
  return _src->get_center_freq( chan );
}

double osmosdr_source_c_impl::set_freq_corr( double ppm, size_t chan )
{
  return _src->set_freq_corr( ppm, chan );
}

double osmosdr_source_c_impl::get_freq_corr( size_t chan )
{
  return _src->get_freq_corr( chan );
}

std::vector<std::string> osmosdr_source_c_impl::get_gain_names( size_t chan )
{
  return _src->get_gain_names( chan );
}

osmosdr::gain_range_t osmosdr_source_c_impl::get_gain_range( size_t chan )
{
  return _src->get_gain_range( chan );
}

osmosdr::gain_range_t osmosdr_source_c_impl::get_gain_range( const std::string & name, size_t chan )
{
  return _src->get_gain_range( name, chan );
}

double osmosdr_source_c_impl::set_gain( double gain, size_t chan )
{
  return _src->set_gain( gain, chan );
}

double osmosdr_source_c_impl::set_gain( double gain, const std::string & name, size_t chan)
{
  return _src->set_gain( gain, name, chan );
}

double osmosdr_source_c_impl::get_gain( size_t chan )
{
  return _src->get_gain( chan );
}

double osmosdr_source_c_impl::get_gain( const std::string & name, size_t chan )
{
  return _src->get_gain( name, chan );
}

std::vector< std::string > osmosdr_source_c_impl::get_antennas( size_t chan )
{
  return _src->get_antennas( chan );
}

std::string osmosdr_source_c_impl::set_antenna( const std::string & antenna, size_t chan )
{
  return _src->set_antenna( antenna, chan );
}

std::string osmosdr_source_c_impl::get_antenna( size_t chan )
{
  return _src->get_antenna( chan );
}
