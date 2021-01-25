/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2021 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/assert.h"
#include "libc/nexgen32e/x86feature.h"
#include "libc/sysv/errfuns.h"
#include "net/http/uri.h"

/*
 * GENERATED BY
 *
 *     ragel -o net/http/uricspn.c net/http/uricspn.rl
 *
 * TODO(jart): Rewrite in normal C.
 */

#define static

/* clang-format off */

#line 29 "net/http/uricspn.rl"

#line 34 "build/bootstrap/net/http/uricspn.c"
static const char _uricspn_key_offsets[] = {
	0, 0
};

static const char _uricspn_trans_keys[] = {
	33, 61, 95, 126, 36, 59, 63, 90, 
	97, 122, 0
};

static const char _uricspn_single_lengths[] = {
	0, 4
};

static const char _uricspn_range_lengths[] = {
	0, 3
};

static const char _uricspn_index_offsets[] = {
	0, 0
};

static const char _uricspn_trans_targs[] = {
	1, 1, 1, 1, 1, 1, 1, 0, 
	0
};

static const int uricspn_start = 1;
static const int uricspn_first_final = 1;
static const int uricspn_error = 0;

static const int uricspn_en_machina = 1;


#line 30 "net/http/uricspn.rl"
/* clang-format on */

int uricspn(const char *data, size_t size) {
  int uricspn$avx(const char *, size_t) hidden;
  const char *p, *pe;
  int cs;

  assert(data || !size);
  assert(size <= 0x7ffff000);
  assert(size <= 0x7ffff000);

  if (X86_HAVE(AVX)) {
    return uricspn$avx(data, size);
  }

  p = data;
  pe = data + size;

  /* clang-format off */

  
#line 56 "net/http/uricspn.rl"


  
#line 94 "build/bootstrap/net/http/uricspn.c"
	{
	cs = uricspn_start;
	}

#line 59 "net/http/uricspn.rl"
  cs = uricspn_en_machina;
  
#line 102 "build/bootstrap/net/http/uricspn.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _uricspn_trans_keys + _uricspn_key_offsets[cs];
	_trans = _uricspn_index_offsets[cs];

	_klen = _uricspn_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _uricspn_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _uricspn_trans_targs[_trans];

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 61 "net/http/uricspn.rl"

  /* clang-format on */

  if (cs >= uricspn_first_final) {
    return p - data;
  } else {
    return einval();
  }
}